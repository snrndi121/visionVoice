/*
  This source is for preprocessing images from original only mouth data.
  Now, there are 4 steps, which are 'resize', 'sharpening', 'contouring', 'image merging'.
  Afterall, One result file will be made from here.
*/
//opencv
// #include "opencv2/objdetect.hpp"
// #include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/face.hpp"
//c++
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
using namespace cv;
// using namespace cv::face;

//def
#define MIN_CANNY_THRESH 100
#define MAX_CANNY_THRESH 180

const string IMG_PATH[] = {"/media/uki408/Seagate Expansion Drive1/Mouth/", "./dst/"};
const string IMG_FOLDER[] = {"resize/", "sharp/", "canny/", "contour/"};
const string DST_FILE_NAME[] = {"r", "s", "c", "ct"};
const string IMG_EXTENDER = ".png";
stringstream fileName;

/* drive */
void drawCanny(const string&, const int, bool);
void SticherCanny();
/* module */
void resizeNfill(const string&, const int, bool);
void sharpening(const string&, const int, bool);
Mat canny_edge(Mat&);
vector <Mat> readImgFile(const string&, const string&, int);

int main(int argc, char** argv)
{
      vector <Mat> imgs = readImgFile(IMG_PATH[0]+IMG_FOLDER[3], IMG_PATH[0]+IMG_FOLDER[3],  IMREAD_GRAYSCALE);
      for (int i = 0; i< 500; ++i) {
          Mat m = imgs[i].clone();
          imshow("res", m);
          waitKey();
      }
      // resizeNfill(IMG_PATH[0]+IMG_FOLDER[3], 0, false);//source path, dst-filetag
      // sharpening(IMG_PATH[0]+IMG_FOLDER[0], 1, false);
      // drawCanny(IMG_PATH[0]+IMG_FOLDER[1], 2, false);
      //파일 저장
      return 0;
}
void drawCanny(const string& _imgPath, const int _fileTag, bool _overwrite)
{
    vector <Mat> imgs = readImgFile(_imgPath, _imgPath, IMREAD_GRAYSCALE);
    fileName << DST_FILE_NAME[_fileTag];
    //if() : 모든 파일에 대하여
    //저장 폴더
    int cnt = 0;
    string DST = IMG_PATH[0]+IMG_FOLDER[_fileTag];
    stringstream fn_src, fn_canny, fn_etc;
    ofstream ofs(DST + "train.txt");// ./dst/ + canny_ + list.txt
    for (int i = 0; i < imgs.size(); ++i) {
        //사진 원본소스 읽기
        /*
          * 명암비 조정
        */
        float alpha = 1.f;
        imgs[i] += (imgs[i]-128) *alpha;
        /*
          * 캐니
        */
        Mat canny_img = canny_edge(imgs[i]);
        //
        // cout << "size:" << canny_img.size()
        // << ", total:"<< canny_img.total()// << endl;
        // << ", type:"<< canny_img.type()
        // << ", depth:"<< canny_img.depth()
        // << ", channels:"<< canny_img.channels() << endl;
        //Canny 변환된 내용 출력하기
        fn_canny << fileName.str() << i;
        ofs << fn_canny.str() << endl;
        fn_canny << IMG_EXTENDER;
        //
        /*
          * 이진화
        */
          // Mat binary_img;
          // threshold(imgs[i], binary_img, 0, 255, THRESH_BINARY | THRESH_OTSU);
          // // dilate(binary_img, binary_img, Mat());
          // // dilate(binary_img, binary_img, Mat());
          // // dilate(binary_img, binary_img, Mat());
          // imshow("sam", binary_img);
          // waitKey();
          // fn_etc.clear();fn_etc.str("");
        /*
          * 외곽선
        */
        // vector <vector <Point> > contours;
        // vector <Vec4i> hierarchy;
        // findContours(canny_img, contours, hierarchy, RETR_LIST, CHAIN_APPROX_SIMPLE);
        //
        // Mat dst;
        // cvtColor(canny_img, dst, COLOR_GRAY2BGR);
        //
        // for (int idx = 0; idx >=0; idx = hierarchy[idx][0]) {
        //     Scalar c(rand()& 255, rand() &255, rand() &255);
        //     drawContours(dst, contours, idx, c, -1, LINE_8, hierarchy);
        // }
        // imshow("res", dst);
        // waitKey();
        // imwrite(fn_etc.str(), dst);
        // fn_etc.clear();fn_etc.str("");

        imwrite(DST+fn_canny.str(), canny_img);
        fn_canny.clear();fn_canny.str("");
        //progress
    }
    ofs.close();
}
void resizeNfill(const string& _imgPath, const int _fileTag, bool _overwrite)
{
    cout << "# resizeNfill " << endl;
    //part1.최대 사이즈 구하기
    vector <Mat> imgs = readImgFile(_imgPath, _imgPath, IMREAD_UNCHANGED);
    fileName << DST_FILE_NAME[_fileTag];
    int max_rows = 0, max_cols = 0;
    vector <Mat>::iterator it =imgs.begin();
    for (; it !=imgs.end(); ++it) {
        max_rows = max(max_rows, it->rows);
        max_cols = max(max_cols, it->cols);
    }
    //저장 폴더
    string DST = IMG_PATH[0]+IMG_FOLDER[_fileTag];
    //part2. 빈데이터 채우기
    ofstream ofs(DST + "train.txt");
    string fn;
    stringstream fn_str;
    for (int i = 0; i < imgs.size(); ++i) {
        /*
          * 크기 조정
        */
        fn_str << fileName.str() << i;
        ofs << fn_str.str() << endl;
        fn_str << IMG_EXTENDER;
        //
        resize(imgs[i], imgs[i], Size(480, 360), INTER_CUBIC);
        //
        imwrite(DST + fn_str.str(), imgs[i]);
        fn_str.clear();fn_str.str("");
    }
    ofs.close();
}
void sharpening(const string& _imgPath, const int _fileTag, bool _overwrite)
{
    cout << "# sharpening " << endl;
    //part1.최대 사이즈 구하기
    vector <Mat> imgs = readImgFile(_imgPath, _imgPath, IMREAD_UNCHANGED);
    fileName << DST_FILE_NAME[_fileTag];

    //저장 폴더
    string DST = IMG_PATH[0]+IMG_FOLDER[_fileTag];
    //part2. 빈데이터 채우기
    const int sigma = 10;
    ofstream ofs(DST+"train.txt");
    stringstream fn_str;
    for (int i = 0; i < imgs.size(); ++i) {
        Mat blurred;
        GaussianBlur(imgs[i], blurred, Size(), sigma);

        float alpha = 1.f;
        Mat dst = (1 + alpha) * imgs[i] - alpha * blurred;
        //
        fn_str << fileName.str() << i;
        ofs << fn_str.str() << endl;
        fn_str << IMG_EXTENDER;
        //
        imwrite(DST + fn_str.str(), dst);
        //
        fn_str.clear();fn_str.str("");
    }
    ofs.close();
}
vector <Mat> readImgFile(const string& _imgListPath, const string& _imgPath, int _flags=IMREAD_COLOR) {
     cout << "# readImgFile " << endl;
    ifstream ifs(_imgListPath + "train.txt");
    cout << " > img list path : " << _imgListPath << endl;
    cout << " > img path :" << _imgPath << endl;
    vector <Mat> imgs;
    stringstream fn_src;
    string fn;
    uint cnt = 0;
    while(ifs >> fn) {
        fn_src.str(_imgPath + fn + IMG_EXTENDER);
        Mat img = imread(fn_src.str(), _flags);
        //
        if (img.empty()) {
            cerr << "img load failed" << endl;
            return imgs;
        }
        cout << " > read :" << fn_src.str() << endl;
        imgs.push_back(img);
        if (++cnt > 500) break;
        fn_src.clear();fn_src.str("");
    }
    ifs.close();
    return imgs;
}
Mat canny_edge(Mat& _src)
{
    Mat _dst;
    Canny(_src, _dst, MIN_CANNY_THRESH, MAX_CANNY_THRESH);
    return _dst;
}
