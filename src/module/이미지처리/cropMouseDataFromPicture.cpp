
/*
  ver1.0 : faceLandMakr + face_eye_detect
*/
//opencv
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/face.hpp>

//c++
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;
using namespace cv;
using namespace cv::face;

//def
#define MAX_MOUTH_CNT 50

//분류기
CascadeClassifier face_cascade;
CascadeClassifier mouth_cascade;
//얼굴 LBF 모델
Ptr<Facemark> facemark = FacemarkLBF::create();// Create an instance of Facemark
/* drive */
void setMouthData(float);
float calAVGMouth();
// void readMouthFromCam();
/* method */
vector < Mat > GetMouthFromFaces(Mat&, vector<Rect_<int> >);
/* module */
Rect GetAdjRect(const Mat& _src, const Rect& _dst, const unsigned int _rest);
void detectFaces(Mat&, vector<Rect_<int> >&);
void detectMouth(Mat&, vector<Rect_<int> >&);
//var
const string SRC_IMG_PATH = "/media/uki408/Seagate Expansion Drive1/";
const string SRC_IMG_FOLDER = "VOCmouth/PNGImages/";
const string SRC_TRAIN_LIST_FOLDER = "VOCmouth/ImageSets/Main/";
const string DST_IMG_PATH = "/media/uki408/Seagate Expansion Drive1/";
const string DST_IMG_FOLDER = "Mouth/";
const string ERR_IMG_FOLDER = "err/";
const string IMG_EXTENDER = ".png";
int main(int argc, char** argv)
{
      //분류기 선언
      face_cascade.load("/usr/local/share/opencv4/haarcascades/haarcascade_frontalface_alt2.xml");
      mouth_cascade.load("./haarcascade_mcs_mouth.xml");
      //분류기 유효 판단
      if (face_cascade.empty() || mouth_cascade.empty()) {
        cout << "File missing" << endl;
        return 1;
      }
      /*
        * 장치 4 : 입술 영역 통계 구하기
      */
      // float avgMouthArea = calAVGMouth();
      setMouthData(3000);//by File
      // readMouthFromCam();//by Cam
      return 0;
}
//
float calAVGMouth()
{
    ifstream ifs(SRC_IMG_PATH + SRC_TRAIN_LIST_FOLDER + "trainval.txt");
    ofstream ofs("./mouthArea_data.md");
    if (ifs.fail()) {
        cerr << "The input file list is missgng" << endl;
        return -1;
    }
    stringstream in_file;
    string fn;
    uint total = 0, left = 0, m_sum = 0 ;
    float avgMA = 0;
    while(ifs >> fn) {
        in_file.str(SRC_IMG_PATH + SRC_IMG_FOLDER + fn + IMG_EXTENDER);
        Mat frame = imread(in_file.str(), IMREAD_UNCHANGED);
        //파일 이미지 존재 확인
        if (frame.empty()) {
            cerr << " > img is missing" << endl;
            cerr << " >> not found :" <<  in_file.str() << endl;
            return -1;
        }
        //입술 찾아아서 저장
        vector<Rect_<int> > faces;
        detectFaces(frame, faces);
        //
        vector<Mat> mouth = GetMouthFromFaces(frame, faces);
        for (uint i=0; i<mouth.size(); ++i) {
            uint ma = mouth[i].rows*mouth[i].cols;
            m_sum += ma;//평균구하기
            ofs << ma << endl;//편차, 표준분산구하기
            total++;
            left++;
        }
        //canaria-overflow
        // cout << "#s:" << ++left << endl;
        //중간결산
        if (left % MAX_MOUTH_CNT == 0) {
            cout << "# round(" << (total/MAX_MOUTH_CNT) << ")" << endl;
              // cout << " > prev_avg :" << avgMA << endl;
              // cout << " > add_sum :" << m_sum << endl;
            m_sum += avgMA*(total-MAX_MOUTH_CNT);
              // cout << " > total_sum :" << m_sum << endl;
            avgMA = total > 0? m_sum/total : total;
              // cout << " > total_avg :" << avgMA << endl;
            m_sum = left = 0;
        }
        //진행상황체크
        // if (total >= 100) break;
        //파일스트림 초기화
        in_file.clear();
    }
    ofs.close();
    //avg
    avgMA = total > 0? (m_sum + avgMA*(total-left))/total : 0;
    //deviation
    ifstream m_ifs("./mouthArea_data.md");
    cout << "> sample size :" << total << endl;
    float dev = 0;
    uint ma;
    while (m_ifs >> ma) { dev += pow(avgMA-ma, 2);}
    ifs.close();
    dev /= total;
    cout << "> mean :" << avgMA << endl;
    cout << "> deviation :" << dev << endl;
    cout << "> standard deviation :" << sqrt(dev) << endl;
    cout << "> diff :" << (sqrt(dev)/avgMA) * 100 << endl;
    return avgMA-sqrt(dev);
}
void setMouthData(float _minMouthArea)
{
    cout << "\n# setMouthData got MIN_MOUTH_AREA : " << _minMouthArea << endl;
    ifstream ifs(SRC_IMG_PATH + SRC_TRAIN_LIST_FOLDER + "trainval.txt");
    if (ifs.fail()) {
        cerr << "The input file list is missgng" << endl;
        return ;
    }
    stringstream in_file, out_file, err_file;
    string fn;
    uint cnt = 0;
    while(ifs >> fn) {
        in_file.str(SRC_IMG_PATH + SRC_IMG_FOLDER + fn + IMG_EXTENDER);
        Mat frame = imread(in_file.str(), IMREAD_UNCHANGED);
        //파일 이미지 존재 확인
        if (frame.empty()) {
            cerr << " > img is missing" << endl;
            cerr << " >> not found :" <<  in_file.str() << endl;
            return;
        }
        //입술 찾아아서 저장
        out_file.str(DST_IMG_PATH + DST_IMG_FOLDER + fn + IMG_EXTENDER);
        err_file.str(DST_IMG_PATH + DST_IMG_FOLDER + ERR_IMG_FOLDER + fn + IMG_EXTENDER);
        /*
          * 장치1 : 전체 영역에서 얼굴 영역 ROI 타겟팅
        */
        vector<Rect_<int> > faces;
        detectFaces(frame, faces);
        //
        vector<Mat> mouth = GetMouthFromFaces(frame, faces);
        for (uint i=0; i<mouth.size(); ++i) {
            if(mouth[i].rows*mouth[i].cols >= _minMouthArea)
              imwrite(out_file.str(), mouth[i]);//출력
            else
              imwrite(err_file.str(), mouth[i]);
        }
        //진행상황체크
        cout << "#s:" << ++cnt << endl;
        // if (cnt >= 200) break;
        //파일스트림 초기화
        in_file.clear();
        out_file.clear();
        err_file.clear();
    }
}
//입술 영역 재조정
Rect GetAdjRect(const Mat& _src, const Rect& _dst, const unsigned int _rest) {
    Rect res = _dst;
    static uint _adj_height=_rest*3;
    res.x = res.x -_rest >= 0? res.x -_rest : 0;
    res.y = res.y -_rest >= 0? res.y -_rest : 0;
    res.width = res.x + res.width +_rest <= _src.cols?
              (res.width +_rest) : (res.width + (_src.cols-res.x-res.width)/2);
    res.height = res.y + res.height +_adj_height <= _src.rows?
            (res.height +_adj_height) : (res.height + (_src.rows-res.y-res.height)/2);
    return res;
}
vector <Mat> GetMouthFromFaces(Mat& img, vector<Rect_<int> > faces)
{
    /*
      * 장치3 : 여유있게 출력
    */
    static uint count = 0;
    const unsigned int REST = 7;
    vector < Mat > res;
    for(unsigned int i = 0; i < faces.size(); ++i) {
            Rect face = faces[i];
            //* deprecated : rectangle(img, Point(face.x, face.y), Point(face.x + face.width, face.y + face.height + adj_rest), Scalar(0, 255, 0), 1, 4);
            rectangle(img, GetAdjRect(img, face, REST), Scalar(0, 255, 0), 1, 4);
            Mat F_ROI = img(GetAdjRect(img, face, REST));//얼굴 영역을 따로 추출해옴
            if(!mouth_cascade.empty())//입 분류기 존재시
            {
                vector<Rect_<int> > mouth;
                detectMouth(F_ROI, mouth);//얼굴에서 입찾기
                /*
                  * 장치2 : mouth가 여러개 나왔다면 높이가 제일 높은 녀석 = 진짜 mouse
                */
                if (mouth.size() > 0) {  //입 자체가 먼저 인지된다면,
                    unsigned int real = 0;
                    for(unsigned int j = 0; j < mouth.size(); ++j) {//입술 영역 표시
                        if (mouth[real].y < mouth[j].y) { real = j;}
                    }
                    //mouth.size() == 1 && 눈이 아닌 경우
                    Rect m = mouth[real];
                    rectangle(F_ROI, GetAdjRect(F_ROI, m, REST), Scalar(0, 255, 0), 1, 4);
                    if (mouth[real].y > F_ROI.rows/2) {
                        //* deprecated : rectangle(F_ROI, Point(m.x-REST, m.y-REST*2), Point(m.x + m.width + REST, m.y + m.height + REST), Scalar(0, 255, 0), 1, 4);
                        Mat M_ROI = F_ROI(GetAdjRect(F_ROI, m, REST));//얼굴 영역을 따로 추출해옴
                        res.push_back(M_ROI);
                    } else {
                        stringstream eye_out;
                        eye_out << DST_IMG_PATH + DST_IMG_FOLDER + "eye/";
                        eye_out << count++;
                        eye_out << IMG_EXTENDER;
                        cout << eye_out.str() << endl;
                        imwrite(eye_out.str(), F_ROI);
                    }
                }
            }
      }
      return res;
}
//분류기 : 얼굴검출
void detectFaces(Mat& img, vector<Rect_<int> >& faces)
{
  if (!face_cascade.empty())
    face_cascade.detectMultiScale(img, faces, 1.15, 3, 0|CASCADE_SCALE_IMAGE, Size(30, 30));
  return;
}
//분류기 : 입검출
void detectMouth(Mat& img, vector<Rect_<int> >& mouth)
{
    if (!mouth_cascade.empty())
        mouth_cascade.detectMultiScale(img, mouth, 1.20, 5, 0|CASCADE_SCALE_IMAGE, Size(30, 30));
    return;
}
// void readMouthFromCam()
// {
//     // //얼굴 특징 모델 로드
//     // facemark->loadModel("./lbfmodel.yaml");
//     //카메라 변수 선언
//     bool display_mode = true;
//     VideoCapture cap(0);
//     cap.set(CAP_PROP_FRAME_WIDTH, 640);
//     cap.set(CAP_PROP_FRAME_HEIGHT, 480);
//
//     //이미지 및 분류기 동작
//     Mat frame;
//     cout << " (notice) If you want draw only mouth, then push 'space'. That's the switch button.\n";
//     while (cap.read(frame)) {
//         vector<Rect_<int> > mouth;
//         static int stage = 0;
//
//         //Part1. 얼굴 찾고 얼굴 안에서 입 찾고 사각 처리{Detect faces and facial features}
//         WriteMouthFromFaces(frame, "sam");
//         // imshow("Result", frame);
//
//         //동작 조작 부분
//         char c = waitKey(1);
//         if( c == 'q' || c == 'Q' || c == 27 ) {
//             cap.release();
//             break;
//         }
//         else if( c == ' ' ) {
//             cout << "\n\n #### Switch :Draw only mouth #### \n";
//             cout << ">> switch : " << display_mode << endl;
//             display_mode = !display_mode;
//         }
//     }
// }
