
/*
  ver1.0 : faceLandMakr + face_eye_detect
*/
//opencv
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/face.hpp>
#include "../drawLandmarks.hpp"
//c++
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;
using namespace cv;
using namespace cv::face;

//def
#define NUM_TEST_CASE 10
#define MAX_MOUTH_CNT 5
#define NUM_LANDMARK 68
#define START_LIPS_IDX 48
#define END_LIPS_IDX 67
//분류기
CascadeClassifier face_cascade;
CascadeClassifier mouth_cascade;
//얼굴 LBF 모델
Ptr<Facemark> facemark = FacemarkLBF::create();// Create an instance of Facemark
/* drive */
void setMouthData1(float);
void setMouthData2(float);
// void readMouthFromCam();
/* module */
float calAVGMouth();
vector < Mat > GetMouthFromFaces(Mat&, vector<Rect_<int> >);
void drawContour(Mat&, vector<Point2f> &);
Rect GetAdjRect(const Mat& _src, const Rect& _dst, const unsigned int _rest);
Rect GetContourArea(vector <Point2f> &_fl);
void writeMouthXY(vector <Point2f> &, bool);
void drawCircleOn(Mat&, vector <Point2f> &);
void detectFaces(Mat&, vector<Rect_<int> >&);
void detectMouth(Mat&, vector<Rect_<int> >&);
//var
const string SRC_IMG_PATH = "/media/uki408/Seagate Expansion Drive1/VOCmouth/";
const string SRC_IMG_FOLDER[] = {"ImageSets/Main/", "PNGImages/"};
const string SRC_TRAIN_LIST_FOLDER = "VOCmouth/ImageSets/Main/";
const string DST_IMG_PATH = "/media/uki408/Seagate Expansion Drive1/Mouth/";
const string DST_IMG_FOLDER[] = {"err/", "norm/", "eye/", "contour/"};
const string IMG_EXTENDER = ".png";
const string TEXT_NAME[] = {"./mouthArea_data.md", "./mouth_XY_data.md"};
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
      // setMouthData1(3000);//by File
      setMouthData2(3000);//by File
      // readMouthFromCam();//by Cam
      return 0;
}
/* method */
//raw 입 영역 추출
void setMouthData1(float _minMouthArea)
{
    cout << "\n# setMouthData got MIN_MOUTH_AREA : " << _minMouthArea << endl;
    ifstream ifs(SRC_IMG_PATH + SRC_IMG_FOLDER[0] + "trainval.txt");
    if (ifs.fail()) {
        cerr << "The input file list is missgng" << endl;
        return ;
    }
    stringstream in_file, out_file, err_file;
    string fn;
    uint cnt = 0;
    while(ifs >> fn) {
        in_file.str(SRC_IMG_PATH + SRC_IMG_FOLDER[1] + fn + IMG_EXTENDER);
        Mat frame = imread(in_file.str(), IMREAD_UNCHANGED);
        //파일 이미지 존재 확인
        if (frame.empty()) {
            cerr << " > img is missing" << endl;
            cerr << " >> not found :"<<  in_file.str() << endl;
            return;
        }
        //입술 찾아아서 저장
        out_file.str(DST_IMG_PATH + fn + IMG_EXTENDER);
        err_file.str(DST_IMG_PATH + DST_IMG_FOLDER[0] + fn + IMG_EXTENDER);
        /*
          * 장치1 : 전체 영역에서 얼굴 영역 ROI 타겟팅
        */
        vector<Rect_<int> > faces;
        detectFaces(frame, faces);
        vector<Mat> mouth = GetMouthFromFaces(frame, faces);
        for (uint i=0; i<mouth.size(); ++i) {
            //정상적인 경우
            if(mouth[i].rows*mouth[i].cols >= _minMouthArea) {
              imwrite(out_file.str(), mouth[i]);//출력
            }
            //handling-exception
            else
              imwrite(err_file.str(), mouth[i]);
        }
        //진행상황체크
        cout << "#s:" << ++cnt << endl;
        //파일스트림 초기화
        in_file.clear();
        out_file.clear();
        err_file.clear();
        // if (cnt >= 200) break;
        //count
    }
}
//입 외곽선 -> 입 영역 도출
void setMouthData2(float _minMouthArea)
{
    cout << "\n# setMouthData got MIN_MOUTH_AREA : " << _minMouthArea << endl;
    ifstream ifs(SRC_IMG_PATH + SRC_IMG_FOLDER[0] + "trainval.txt");
    if (ifs.fail()) {
        cerr << "The input file list is missgng" << endl;
        return ;
    }
    stringstream in_file, contour_file, loc_file;
    string fn;
    vector<Point2f> mouthland;
    uint cnt = 0;
    ofstream mlm_ifs(TEXT_NAME[1], ofstream::trunc);
    while(ifs >> fn) {
        in_file.str(SRC_IMG_PATH + SRC_IMG_FOLDER[1] + fn + IMG_EXTENDER);
        Mat frame = imread(in_file.str(), IMREAD_UNCHANGED);
        //파일 이미지 존재 확인
        if (frame.empty()) {
            cerr << " > img is missing" << endl;
            cerr << " >> not found :"<<  in_file.str() << endl;
            return;
        }
        //진행상황체크
        cout << "#s:" << cnt+1 << endl;
        //입술 찾아아서 저장
        contour_file.str(DST_IMG_PATH + DST_IMG_FOLDER[3] + fn + IMG_EXTENDER);
        drawContour(frame, mouthland);
        cout << " > found mouthland size :" << mouthland.size()/END_LIPS_IDX << endl;
        Mat mouth = frame(GetContourArea(mouthland));
        //contour image wrtie
        imwrite(contour_file.str(), mouth);//출력
        /*
          *좌표값 테스트
          drawCircleOn(frame, mouthland);
        */
        //파일스트림 초기화
        in_file.clear();in_file.str("");
        contour_file.clear();contour_file.str("");
        loc_file.clear();loc_file.str("");
        /*
          * 좌표값 저장
        */
        writeMouthXY(mouthland, false);

        //count
        if (++cnt >= NUM_TEST_CASE) break;
    }
    mlm_ifs.close();
    //write rest of mouth location
    writeMouthXY(mouthland, true);
}
/* module */
void drawContour(Mat &_frame, vector <Point2f> &mouthland)//, vector<Rect_<int> > &_faces)
{
    // Mat frame =_frame;
    // Load Face Detector
    CascadeClassifier faceDetector("/usr/local/share/opencv4/haarcascades/haarcascade_frontalface_alt2.xml");
    // Create an instance of Facemark
    Ptr<Facemark> facemark = FacemarkLBF::create();
    // Load landmark detector
    facemark->loadModel("./lbfmodel.yaml");

    // Variable to store a video frame and its grayscale
    Mat gray;
    // Read a frame
    // Find face
    vector<Rect> faces;
    // Convert frame to grayscale because
    // faceDetector requires grayscale image.
    cvtColor(_frame, gray, COLOR_BGR2GRAY);
    // Detect faces
    faceDetector.detectMultiScale(gray, faces);
    // Variable for landmarks.
    // Landmarks for one face is a vector of points
    // There can be more than one face in the image. Hence, we
    // use a vector of vector of points.
    vector< vector<Point2f> > landmarks;
    // Run landmark detector
    bool success = facemark->fit(_frame, faces, landmarks);
    if(success) {
      // If successful, render the landmarks on\ the face
        for(int i = 0; i < landmarks.size(); i++) {
            drawMouthContour(_frame, landmarks[i]);
            //입술 영역 좌표 추출
            for (int j = 0; j < landmarks[i].size(); ++j)
                mouthland.push_back(landmarks[i][j]);
        }
    } else {
        cerr << " > lips detetion fail" << endl;
    }
    // Display results
    // stringstream ss; ss << cnt << ".png";
    // imwrite(ss.str(), _frame);
    // Exit loop if ESC is pressed
}
void drawCircleOn(Mat& _src, vector <Point2f> &_mouthland)
{
    //test
    int idx = _mouthland.size()-NUM_LANDMARK;
    Mat dot_frame = _src.clone();
    for (int i = START_LIPS_IDX; i <= END_LIPS_IDX; ++i) {
        circle(dot_frame, _mouthland[idx+i], 3, Scalar(255, 200,0), FILLED);
    }
    imshow("dot_frame", dot_frame);
    waitKey();
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
            // rectangle(img, GetAdjRect(img, face, REST), Scalar(0, 255, 0), 1, 4);
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
                    // rectangle(F_ROI, GetAdjRect(F_ROI, m, REST), Scalar(0, 255, 0), 1, 4);
                    if (mouth[real].y > F_ROI.rows/2) {
                        //* deprecated : rectangle(F_ROI, Point(m.x-REST, m.y-REST*2), Point(m.x + m.width + REST, m.y + m.height + REST), Scalar(0, 255, 0), 1, 4);
                        Mat M_ROI = F_ROI(GetAdjRect(F_ROI, m, REST));//얼굴 영역을 따로 추출해옴
                        res.push_back(M_ROI);
                    } else {//handling-exception
                        stringstream eye_out;
                        eye_out << DST_IMG_PATH + DST_IMG_FOLDER[2];
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
/* module */
//setMouthData2-입술 영역 재조정
Rect GetContourArea(vector <Point2f> &_fl)
{
    int idx = _fl.size() > 0? _fl.size()-NUM_LANDMARK : 0;
    cout << " > ml size :" << _fl.size() << endl;
    cout << " > idx :" << idx << endl;
    float lx = _fl[idx+48].x - (_fl[idx+48].x - _fl[idx+5].x)/2,
        ly =_fl[idx+51].y - (_fl[idx+51].y - _fl[idx+33].y)/2,
        rx =_fl[idx+54].x + (_fl[idx+11].x - _fl[idx+54].x)/2,
        ry=_fl[idx+57].y + (_fl[idx+8].y - _fl[idx+57].y)/3;
    Rect res(Point(lx, ly), Point(rx, ry));
    return res;
}
//setMouthData1-입술 영역 재조정
Rect GetAdjRect(const Mat& _src, const Rect& _dst, const unsigned int _rest)
{
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
//입 좌표 적기
void writeMouthXY(vector <Point2f> &_mouthland, bool _force)
{
    //저장된 입 좌표 한번 쓰기
    if (_force || _mouthland.size()/NUM_LANDMARK >= MAX_MOUTH_CNT) {
        cout << " > mouth_xy is reporting.." << endl;
        ofstream mlm_ifs(TEXT_NAME[1], ofstream::app);
        for (int i = 0; i < _mouthland.size()/NUM_LANDMARK; ++i) {
            int idx = NUM_LANDMARK*i;
            for (int j = START_LIPS_IDX; j <= END_LIPS_IDX; ++j) {
                mlm_ifs << _mouthland[idx+j].x << "," << _mouthland[idx+j].y << endl;
            }
        }
        _mouthland.clear();
        mlm_ifs.close();
    }
}
float calAVGMouth()
{
    ifstream ifs(SRC_IMG_PATH + SRC_IMG_FOLDER[0] + "trainval.txt");
    ofstream ofs(TEXT_NAME[0]);
    if (ifs.fail()) {
        cerr << "The input file list is missgng" << endl;
        return -1;
    }
    stringstream in_file;
    string fn;
    uint total = 0, left = 0, m_sum = 0 ;
    float avgMA = 0;
    while(ifs >> fn) {
        in_file.str(SRC_IMG_PATH + SRC_IMG_FOLDER[1] + fn + IMG_EXTENDER);
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
    ifstream m_ifs(TEXT_NAME[0]);
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
