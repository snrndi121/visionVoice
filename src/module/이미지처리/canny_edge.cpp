
/*
  ver1.0 : faceLandMakr + face_eye_detect
*/
//opencv
// #include "opencv2/objdetect.hpp"
// #include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"

//c++
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
using namespace cv;
// using namespace cv::face;
//
const string SRC_IMG_PATH = "/media/uki408/Seagate Expansion Drive1/";
const string SRC_IMG_FOLDER = "VOCmouth/PNGImages/";
const string SRC_TRAIN_LIST_FOLDER = "VOCmouth/ImageSets/Main/";
const string DST_IMG_PATH = "/media/uki408/Seagate Expansion Drive1/";
const string DST_IMG_FOLDER = "Mouth/";
const string IMG_EXTENDER = ".png";
const string CANNY_PATH = "./dst/";
const string CANNY_NAME = "canny_";
const string RESIZE_NAME = "resize_";
const string CANNY_HEADER = CANNY_PATH + CANNY_NAME;

/* drive */
void transfromCanny();
void SticherCanny();
/* module */
void resizeNfill();
Mat canny_edge(Mat&);
vector <Mat> readImgFile(const string&, const string&, int);

int main(int argc, char** argv)
{
      transfromCanny();
      resizeNfill();
      SticherCanny();
      //canny_edge() 처리
      //파일 저장
      return 0;
}
void transfromCanny()
{
    //if() : 모든 파일에 대하여
    int cnt = 0;
    stringstream fn_src, fn_canny, fn_etc;
    ifstream ifs(SRC_IMG_PATH+DST_IMG_FOLDER+"train.txt");
    ofstream ofs(CANNY_HEADER + "list.txt");// ./dst/ + canny_ + list.txt
    string fn;
    while(ifs >> fn) {
        //사진 원본소스 읽기
        fn_src << SRC_IMG_PATH << DST_IMG_FOLDER << fn;
        Mat img = imread(fn_src.str(), IMREAD_GRAYSCALE);
        if (img.empty()) {
            cerr << "src is missing" << endl;
            return;
        }
        /*
          * 명암비 조정
        */
        float alpha = 1.f;
        img += (img-128) *alpha;
        /*
          * 캐니
        */
        Mat canny_img = canny_edge(img);
        //
        // cout << "size:" << canny_img.size()
        // << ", total:"<< canny_img.total()// << endl;
        // << ", type:"<< canny_img.type()
        // << ", depth:"<< canny_img.depth()
        // << ", channels:"<< canny_img.channels() << endl;
        //Canny 변환된 내용 출력하기
        ofs << CANNY_NAME << fn << endl;//파일 목록 작성
        fn_canny << CANNY_HEADER << fn;//파일 경로명 추가
        /*
          * 이진화
          fn_etc << FN_PATH << FN_HEADER << cnt << "+threshhold" << FN_EXTENDER;
          Mat binary_img;
          threshold(img, binary_img, 0, 255, THRESH_BINARY | THRESH_OTSU);
          dilate(binary_img, binary_img, Mat());
          dilate(binary_img, binary_img, Mat());
          dilate(binary_img, binary_img, Mat());
          imwrite(fn_etc.str(), binary_img);
          fn_etc.clear();fn_etc.str("");
        */
        /*
          * 외곽선
            fn_etc << FN_PATH << FN_HEADER << cnt << "+contours" << FN_EXTENDER;
            vector <vector <Point> > contours;
            vector <Vec4i> hierarchy;
            findContours(canny_img, contours, hierarchy, RETR_LIST, CHAIN_APPROX_SIMPLE);

            Mat dst;
            cvtColor(canny_img, dst, COLOR_GRAY2BGR);

            for (int idx = 0; idx >=0; idx = hierarchy[idx][0]) {
                Scalar c(rand()& 255, rand() &255, rand() &255);
                drawContours(dst, contours, idx, c, -1, LINE_8, hierarchy);
            }
            imwrite(fn_etc.str(), dst);
            fn_etc.clear();fn_etc.str("");
        */
        imwrite(fn_canny.str(), canny_img);
        fn_src.clear();fn_src.str("");
        fn_canny.clear();fn_canny.str("");
        //exception
        if (++cnt >= 100) break;
    }
    ofs.close();
    ifs.close();
}
void SticherCanny()
{
    vector <Mat> imgs = readImgFile(CANNY_HEADER, "list.txt", IMREAD_COLOR);

    //checker
    for (int i = 0; i < imgs.size(); ++i) {
        cout << "size:" << imgs[i].size() << endl;
        // << ", total:"<< imgs[i].total()
        // << ", type:"<< imgs[i].type()
        // << ", depth:"<< imgs[i].depth()
        // << ", channels:"<< imgs[i].channels()
        // << ", dims :" << imgs[i].dims << endl;
    }
    //
    cout << " >> TestGo :" << imgs.size() << endl;
    Mat dst = Mat::ones(imgs[0].rows, imgs[0].cols, 0);
    //

    Ptr <Stitcher> stitcher = Stitcher::create();
    Stitcher::Status status = stitcher->stitch(imgs, dst);
    cout << " >> done " << endl;
    if (status != Stitcher::Status::OK) {
        cerr << "err on stitching" << endl;
        return ;
    } else {
        cout << "fuck!!!" << endl;
    }
    imwrite("./result.png", dst);
}
/* module */
void resizeNfill()
{
    cout << "# resizeNfill " << endl;
    //part1.최대 사이즈 구하기
    vector <Mat> imgs = readImgFile(CANNY_HEADER,"list.txt", IMREAD_GRAYSCALE);
    int max_rows = 0, max_cols = 0;
    vector <Mat>::iterator it =imgs.begin();
    //
    for (; it !=imgs.end(); ++it) {
        max_rows = max(max_rows, it->rows);
        max_cols = max(max_cols, it->cols);
    }
    //part2. 빈데이터 채우기
    ifstream ifs(CANNY_HEADER + "list.txt");
    string fn;
    stringstream fn_str;
    for (int i = 0; i < imgs.size(); ++i) {
        Mat src = Mat::ones(max_rows, max_cols, 0);//rows, cols, type
        /*
          * 크기 조정
        */
        for (int row = 0; row < imgs[i].rows; ++row)
            for (int col = 0; col < imgs[i].cols; ++col) {
                src.at<uchar>(row,col) = imgs[i].at<uchar>(row, col);
            }
        ifs >> fn;//canny-list 파일명
        // fn_str.str(RESIZE_NAME + fn);//새로 정정된 파일명
        fn_str.str(fn);//새로 정정된 새로 저장
        imwrite(CANNY_PATH + fn_str.str(), src);
        fn_str.clear();fn_str.str("");
    }
    ifs.close();
}
vector <Mat> readImgFile(const string& _path, const string& _name, int _flags=IMREAD_COLOR) {
     cout << "# readImgFile " << endl;
    ifstream ifs(_path + _name);
    //
    vector <Mat> imgs;
    stringstream fn_src;
    string fn;
    uint cnt = 0;
    while(ifs >> fn) {
        fn_src.str(CANNY_PATH + fn);
        // cout << fn_src.str() << endl;
        Mat img = imread(fn_src.str(), _flags);
        //
        if (img.empty()) {
            cerr << "img load failed" << endl;
            return imgs;
        }
        imgs.push_back(img);
        // if (cnt++ > 4) break;
        fn_src.clear();fn_src.str("");
    }
    ifs.close();
    return imgs;
}
Mat canny_edge(Mat& _src)
{
    Mat _dst;
    Canny(_src, _dst, 100, 200);
    return _dst;
}
