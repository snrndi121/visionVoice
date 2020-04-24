
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

using namespace std;
using namespace cv;
using namespace cv::face;

/* Module_1_facial feature detection */
void detectFaces(Mat&, vector<Rect_<int> >&);
void detectMouth(Mat&, vector<Rect_<int> >&);
void WriteMouthFromFaces(Mat&, const string&);

//분류기
CascadeClassifier face_cascade;
CascadeClassifier mouth_cascade;
//얼굴 LBF 모델
Ptr<Facemark> facemark = FacemarkLBF::create();// Create an instance of Facemark
void readMouthFromFile();
// void readMouthFromCam();
//var
const string SRC_IMG_PATH = "/media/uki408/Seagate Expansion Drive1/";
const string SRC_IMG_FOLDER = "VOCmouth/PNGImages/";
const string SRC_TRAIN_LIST_FOLDER = "VOCmouth/ImageSets/Main/";
const string DST_IMG_PATH = "/media/uki408/Seagate Expansion Drive1/";
const string DST_IMG_FOLDER = "Mouth/";
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
      // readMouthFromCam();//by Cam
      readMouthFromFile();//by File
      return 0;
}
void readMouthFromFile()
{
    ifstream ifs(SRC_IMG_PATH + SRC_TRAIN_LIST_FOLDER + "trainval.txt");
    if (ifs.fail()) {
        cerr << "The input file list is missgng" << endl;
        return ;
    }
    stringstream in_file, out_file;
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
        WriteMouthFromFaces(frame, out_file.str());
        //진행상황체크
        cout << "#s:" << ++cnt << endl;
        //파일스트림 초기화
        if (cnt > 20) break;
        in_file.clear();
        out_file.clear();
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
void WriteMouthFromFaces(Mat& img, const string& filename)
{
    //얼굴 먼저
    vector<Rect_<int> > faces;
    detectFaces(img, faces);
    /*
      * 장치3 : 여유있게 출력
    */
    const unsigned int REST = 7;
    for(unsigned int i = 0; i < faces.size(); ++i)
    {
          /*
            * 장치1 : 전체 영역에서 얼굴 영역 ROI 타겟팅
          */
            Rect face = faces[i];
            // rectangle(img, Point(face.x, face.y), Point(face.x + face.width, face.y + face.height + adj_rest), Scalar(0, 255, 0), 1, 4);
            rectangle(img, GetAdjRect(img, face, REST), Scalar(0, 255, 0), 2, 4);
            cout << "{" << endl;
            Mat F_ROI = img(GetAdjRect(img, face, REST));//얼굴 영역을 따로 추출해옴
            cout << "}" << endl;
            if(!mouth_cascade.empty())//입 분류기 존재시
            {
                vector<Rect_<int> > mouth;
                detectMouth(F_ROI, mouth);//얼굴에서 입찾기
                /*
                  * 장치2 : mouth가 여러개 나왔다면 높이가 제일 높은 녀석 = 진짜 mouse
                */
                //입 자체가 먼저 인지된다면,
                if (mouth.size() > 0) {
                    unsigned int real = 0;
                    for(unsigned int j = 0; j < mouth.size(); ++j) {//입술 영역 표시
                        if (mouth[real].y < mouth[j].y) { real = j;}
                    }

                    Rect m = mouth[real];
                    unsigned int adj_m_rest = m.y + m.height+REST > F_ROI.cols? (F_ROI.cols-m.height)/2 : REST;
                    // rectangle(F_ROI, Point(m.x-REST, m.y-REST*2), Point(m.x + m.width + REST, m.y + m.height + REST), Scalar(0, 255, 0), 1, 4);
                    rectangle(F_ROI, GetAdjRect(F_ROI, m, REST), Scalar(0, 255, 0), 2, 4);
                    cout << "{" << endl;
                    // Mat M_ROI = F_ROI(Rect(m.x-REST, m.y-REST*2, m.width+REST, m.height+adj_m_rest));//얼굴 영역을 따로 추출해옴
                    Mat M_ROI = F_ROI(GetAdjRect(F_ROI, m, REST));//얼굴 영역을 따로 추출해옴
                    cout << "}" << endl;
                    // imwrite(filename, img);//출력
                }
          }
      }
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
