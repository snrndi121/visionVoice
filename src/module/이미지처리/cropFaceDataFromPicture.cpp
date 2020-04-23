
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
void drawFaceNMouth(Mat& img, const vector<Rect_<int> > faces, bool both);

//분류기
CascadeClassifier face_cascade;
CascadeClassifier mouth_cascade;
//얼굴 LBF 모델
Ptr<Facemark> facemark = FacemarkLBF::create();// Create an instance of Facemark
void fileProcess(float _x_var, float _y_var);
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
      // //얼굴 특징 모델 로드
      // facemark->loadModel("./lbfmodel.yaml");
      //카메라 변수 선언
      bool display_mode = true;
      VideoCapture cap(0);
      cap.set(CAP_PROP_FRAME_WIDTH, 640);
      cap.set(CAP_PROP_FRAME_HEIGHT, 480);

      //이미지 및 분류기 동작
      Mat frame;
      cout << " (notice) If you want draw only mouth, then push 'space'. That's the switch button.\n";
      while (cap.read(frame)) {
          vector<Rect_<int> > faces;
          static int stage = 0;

          //Part1. 얼굴 찾고 얼굴 안에서 입 찾고 사각 처리{Detect faces and facial features}
          detectFaces(frame, faces);
          drawFaceNMouth(frame, faces, display_mode);
          imshow("Result", frame);

          //동작 조작 부분
          char c = waitKey(1);
          if( c == 'q' || c == 'Q' || c == 27 ) {
              cap.release();
              break;
          }
          else if( c == ' ' ) {
              cout << "\n\n #### Switch :Draw only mouth #### \n";
              cout << ">> switch : " << display_mode << endl;
              display_mode = !display_mode;
          }
      }
      return 0;
}
//출력 : 얼굴과 입 출력
void drawFaceNMouth(Mat& img, const vector<Rect_<int> >faces, bool both)
{
    static uint count= 0;
    stringstream file_name;
    for(unsigned int i = 0; i < faces.size(); ++i)
    {
          //1. 전체 영역에서 얼굴 영역에 대하여 사각형 그리기
          Rect face = faces[i];
          if (both) {
              rectangle(img, Point(face.x, face.y), Point(face.x+face.width, face.y+face.height),
                        Scalar(255, 0, 0), 1, 4);
          }
          //2. 얼굴 영역을 따로 추출해옴.
          Mat ROI = img(Rect(face.x, face.y, face.width, face.height));
          /* 입 영역 추출 코드 : deprecated*/
          file_name << "./dst/sam_" << count++ << ".png";
          imwrite(file_name.str(), ROI);
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
void detectMouth(Mat& img, vector<Rect_<int> >& eyes)
{
    if (!mouth_cascade.empty())
        mouth_cascade.detectMultiScale(img, eyes, 1.20, 5, 0|CASCADE_SCALE_IMAGE, Size(30, 30));
    return;
}
