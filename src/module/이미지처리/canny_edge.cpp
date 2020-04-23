
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

//얼굴 LBF 모델ㅌ
Mat canny_edge(Mat&);
int main(int argc, char** argv)
{
      //파일스트림 생성
      const string fn_dir = "./dst/";
      const string fn_header = "mouse_", fn_extender =".png";
      const string fn_canny = "canny_";
      //if() : 모든 파일에 대하여
      int cnt = 0;
      stringstream fn_src, fn_dst;
      while(1) {
          fn_src << fn_dir << fn_header << cnt++;
          fn_dst.str(fn_src.str()); fn_src << fn_extender;
          //
          Mat img = imread(fn_src.str(), IMREAD_GRAYSCALE);
          if (img.empty()) {
              cerr << "src is missing" << endl;
              return -1;
          }
          //
          Mat canny_img = canny_edge(img);
          //
          fn_dst << fn_canny << fn_extender;
          imwrite(fn_dst.str(), canny_img);
          //
          fn_src.clear();
          fn_dst.clear();
      }
      //canny_edge() 처리
      //파일 저장
      return 0;
}
Mat canny_edge(Mat& _src)
{
    Mat _dst;
    Canny(_src, _dst, 50, 150);
    return _dst;
}
