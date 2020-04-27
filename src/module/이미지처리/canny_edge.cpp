
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
const string SRC_IMG_PATH = "/media/uki408/Seagate Expansion Drive1/Mouth/";
const string SRC_IMG_LIST_PATH= "/media/uki408/Seagate Expansion Drive1/Mouth/";
const string DST_IMG_PATH = "./dst/";
const string DST_IMG_FOLDER[] = {"resize/", "sharp/", "canny/"};
const string DST_FILE_NAME[] = {"r", "s", "c"};
const string IMG_EXTENDER = ".png";

/* drive */
void transfromCanny(const string&, const int);
void SticherCanny();
/* module */
void resizeNfill(const string&, const int);
void sharpening(const string&, const int);
Mat canny_edge(Mat&);
vector <Mat> readImgFile(const string&, const string&, int);

int main(int argc, char** argv)
{
      resizeNfill(SRC_IMG_PATH, 0);//imgpath, filetag
      sharpening(DST_IMG_PATH+DST_IMG_FOLDER[0], 1);
      transfromCanny(DST_IMG_PATH+DST_IMG_FOLDER[1], 2);
      // SticherCanny();
      //파일 저장
      return 0;
}
void transfromCanny(const string& _imgPath, const int _fileTag)
{
    vector <Mat> imgs = readImgFile(_imgPath, _imgPath, IMREAD_GRAYSCALE);

    //if() : 모든 파일에 대하여
    int cnt = 0;
    stringstream fn_src, fn_canny, fn_etc;
    ofstream ofs(DST_IMG_PATH + DST_IMG_FOLDER[_fileTag] + "train.txt");// ./dst/ + canny_ + list.txt
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
        fn_canny << DST_FILE_NAME[_fileTag] << i << IMG_EXTENDER;//파일 경로명 추가
        ofs << fn_canny.str() << endl;
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
        imwrite(DST_IMG_PATH+DST_IMG_FOLDER[_fileTag]+fn_canny.str(), canny_img);
        fn_canny.clear();fn_canny.str("");
    }
    ofs.close();
}
void SticherCanny()
{
    vector <Mat> imgs = readImgFile(DST_IMG_PATH+DST_IMG_FOLDER[0], DST_IMG_PATH+DST_IMG_FOLDER[0], IMREAD_COLOR);

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

    Ptr <Stitcher> stitcher = Stitcher::create(Stitcher::SCANS);
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
void resizeNfill(const string& _imgPath, const int _fileTag)
{
    cout << "# resizeNfill " << endl;
    //part1.최대 사이즈 구하기
    vector <Mat> imgs = readImgFile(_imgPath, _imgPath, IMREAD_GRAYSCALE);
    int max_rows = 0, max_cols = 0;
    vector <Mat>::iterator it =imgs.begin();
    for (; it !=imgs.end(); ++it) {
        max_rows = max(max_rows, it->rows);
        max_cols = max(max_cols, it->cols);
    }
    //part2. 빈데이터 채우기
    // ifstream ifs(_imgPath+"train.txt");
    ofstream ofs(DST_IMG_PATH+DST_IMG_FOLDER[_fileTag]+ "train.txt");
    string fn;
    stringstream fn_str;
    for (int i = 0; i < imgs.size(); ++i) {
        // Mat src = Mat::ones(max_rows, max_cols, 0);//rows, cols, type
        /*
          * 크기 조정
        */
        // ifs >> fn;//canny-list 파일명
        fn_str << DST_FILE_NAME[_fileTag] << i << IMG_EXTENDER;//새로 정정된 새로 저장
        ofs << fn_str.str() << endl;
        resize(imgs[i], imgs[i], Size(480, 360), INTER_CUBIC);
        imwrite(DST_IMG_PATH + DST_IMG_FOLDER[_fileTag] + fn_str.str(), imgs[i]);
        fn_str.clear();fn_str.str("");
    }
    // ifs.close();
    ofs.close();
}
// void resizeNfill()
// {
//     cout << "# resizeNfill " << endl;
//     //part1.최대 사이즈 구하기
//     vector <Mat> imgs = readImgFile(SRC_IMG_PATH+DST_IMG_FOLDER+"train.txt", SRC_IMG_PATH+DST_IMG_FOLDER, IMREAD_GRAYSCALE);
//     int max_rows = 0, max_cols = 0;
//     vector <Mat>::iterator it =imgs.begin();
//     for (; it !=imgs.end(); ++it) {
//         max_rows = max(max_rows, it->rows);
//         max_cols = max(max_cols, it->cols);
//     }
//     //part2. 빈데이터 채우기
//     ifstream ifs(SRC_IMG_PATH+DST_IMG_FOLDER+"train.txt");
//     string fn;
//     stringstream fn_str;
//     for (int i = 0; i < imgs.size(); ++i) {
//         Mat src = Mat::ones(max_rows, max_cols, 0);//rows, cols, type
//         /*
//           * 크기 조정
//         */
//         for (int row = 0; row < imgs[i].rows; ++row)
//             for (int col = 0; col < imgs[i].cols; ++col) {
//                 src.at<uchar>(row,col) = imgs[i].at<uchar>(row, col);
//             }
//         ifs >> fn;//canny-list 파일명
//         // fn_str.str(RESIZE_NAME + fn);//새로 정정된 파일명
//         fn_str.str(fn);//새로 정정된 새로 저장
//         resize(src, src, Size(), 4, 4, INTER_CUBIC);
//         imwrite(CANNY_PATH + fn_str.str(), src);
//         fn_str.clear();fn_str.str("");
//     }
//     ifs.close();
// }
void sharpening(const string& _imgPath, const int _fileTag)
{
    cout << "# sharpening " << endl;
    //part1.최대 사이즈 구하기
    vector <Mat> imgs = readImgFile(_imgPath, _imgPath, IMREAD_COLOR);
    //part2. 빈데이터 채우기
    const int sigma = 10;
    ofstream ofs(DST_IMG_PATH+DST_IMG_FOLDER[_fileTag]+"train.txt");
    for (int i = 0; i < imgs.size(); ++i) {
        Mat blurred;
        GaussianBlur(imgs[i], blurred, Size(), sigma);

        float alpha = 1.f;
        Mat dst = (1 + alpha) * imgs[i] - alpha * blurred;
        stringstream ss;
        ss << DST_FILE_NAME[_fileTag] << i << IMG_EXTENDER;
        ofs << ss.str() << endl;
        imwrite(DST_IMG_PATH + DST_IMG_FOLDER[_fileTag] + ss.str(), dst);
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
        fn_src.str(_imgPath + fn);
        // cout << fn_src.str() << endl;
        Mat img = imread(fn_src.str(), _flags);
        //
        if (img.empty()) {
            cerr << "img load failed" << endl;
            return imgs;
        }
        cout << " > read :" << fn_src.str() << endl;
        imgs.push_back(img);
        if (cnt++ > 10) break;
        fn_src.clear();fn_src.str("");
    }
    ifs.close();
    return imgs;
}
Mat canny_edge(Mat& _src)
{
    Mat _dst;
    Canny(_src, _dst, 50, 150);
    return _dst;
}
