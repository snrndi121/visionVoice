
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
#define TEST_CASE_ON false
#define MAX_MOUTH_CNT 100
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
void drawContour2(Mat &_frame, vector <Point2f> &mouthland, bool _success);
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
const string TEXT_NAME[] = {"./mouthArea_data.md", "./mouth_XY_data.md", "train.txt"};

int main(int argc, char** argv)
{
      face_cascade.load("/usr/local/share/opencv4/haarcascades/haarcascade_frontalface_alt2.xml");
      mouth_cascade.load("./haarcascade_mcs_mouth.xml");
      if (face_cascade.empty() || mouth_cascade.empty()) {
        cout << "File missing" << endl;
        return 1;
      }
      // float avgMouthArea = calAVGMouth();
      // setMouthData1(3000);//by File
      setMouthData2(3000);//by File
      return 0;
}
/*
  * method
*/
//Save only mouth image as '.png'
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
//Draw mouth contour and save it as '.png'
void setMouthData2(float _minMouthArea)
{
    cout << "\n# setMouthData got MIN_MOUTH_AREA : " << _minMouthArea << endl;
    ifstream ifs(SRC_IMG_PATH + SRC_IMG_FOLDER[0] + "trainval.txt");
    if (ifs.fail()) {
        cerr << "The input file list is missgng" << endl;
        return ;
    }
    facemark->loadModel("./lbfmodel.yaml");
    vector<Point2f> mouthland;
    stringstream in_file, contour_file, loc_file;
    string fn;
    uint cnt = 0;
    ofstream mlm_ifs(TEXT_NAME[1], ofstream::trunc);
    ofstream fn_list(DST_IMG_PATH + DST_IMG_FOLDER[3] + TEXT_NAME[2]);
    while(ifs >> fn) {
        /*
          * Declaration
        */
        in_file.str(SRC_IMG_PATH + SRC_IMG_FOLDER[1] + fn + IMG_EXTENDER);
        contour_file.str(DST_IMG_PATH + DST_IMG_FOLDER[3] + fn + IMG_EXTENDER);
        Mat frame = imread(in_file.str(), IMREAD_UNCHANGED);
        /*
          * File checking
        */
        if (frame.empty()) {
            cerr << " > img is missing" << endl;
            cerr << " >> not found :"<<  in_file.str() << endl;
            return;
        }
        /*
          * Fine mouth and drawing
        */
        drawContour(frame, mouthland);
        Mat mouth = frame(GetContourArea(mouthland));
        /*
          * messaging
        */
        cout << " # s:" << cnt+1;
        cout << ", m:" << mouthland.size()/NUM_LANDMARK << endl;

        /*
          * Output
        */
        imwrite(contour_file.str(), mouth);
        writeMouthXY(mouthland, false);
        fn_list << fn << endl;

        /*
          * Test mouth XY location
        */
        // drawCircleOn(frame, mouthland);

        /*
          * Limit testcase
        */
        if (++cnt >= NUM_TEST_CASE && TEST_CASE_ON) break;

        /*
          * initializing
        */
        in_file.clear();in_file.str("");
        contour_file.clear();contour_file.str("");
        loc_file.clear();loc_file.str("");
    }
    mlm_ifs.close();
    fn_list.close();
    //write rest of 'mouthland'
    writeMouthXY(mouthland, true);
}
/*
  * module
*/
void drawContour(Mat &_frame, vector <Point2f> &mouthland)
{
    // Variable to store a video frame and its grayscale
    Mat gray;
    // Find face
    vector<Rect> faces;
    detectFaces(_frame, faces);
    uint target = 0;
    if (faces.size() > 1) {
        cout << " > multi face is detected.." << endl;
        for (uint i = 1; i < faces.size(); ++i) {
            target = faces[target].width < faces[i].width? i : target;
        }
    }
    // Variable for landmarks.
    // Landmarks for one face is a vector of points
    // There can be more than one face in the image. Hence, we
    // use a vector of vector of points.
    vector< vector<Point2f> > landmarks;
    // Run landmark detector
    bool success = facemark->fit(_frame, faces, landmarks);
    if(success) {
      // If successful, render the landmarks on\ the face
        drawMouthContour(_frame, landmarks[target]);
        for (int j = 0; j < landmarks[target].size(); ++j) {
            if (landmarks[target].size() == NUM_LANDMARK) { mouthland.push_back(landmarks[target][j]);}
            else { cerr << " > landmark is under uncompleted state." << endl;}
        }
    } else {
        cerr << " > lips detetion fail" << endl;
    }
}
//Mark circle from Point on 'image source'
void drawCircleOn(Mat& _src, vector <Point2f> &_mouthland)
{
    int idx = _mouthland.size()-NUM_LANDMARK;
    Mat dot_frame = _src.clone();
    for (int i = START_LIPS_IDX; i <= END_LIPS_IDX; ++i) {
        circle(dot_frame, _mouthland[idx+i], 3, Scalar(255, 200,0), FILLED);
    }
    imshow("dot_frame", dot_frame);
    waitKey();
}
//GetMouthFromFaces() : Extract mouth Image from face and Save it
/*
  * part1 : it will expand soure image enough to get meaningful information.
  * part2 : it will choose the biggest 'y' to get real mouth images.
  * part3 : it assume that the real mouth is below face.height/2.
*/
vector <Mat> GetMouthFromFaces(Mat& img, vector<Rect_<int> > faces)
{
    static uint count = 0;
    const unsigned int REST = 7;
    vector < Mat > res;
    for(unsigned int i = 0; i < faces.size(); ++i) {
            Rect face = faces[i];
            /*
              * part1
            */
            Mat F_ROI = img(GetAdjRect(img, face, REST));
            if(!mouth_cascade.empty())
            {
                vector<Rect_<int> > mouth;
                detectMouth(F_ROI, mouth);
                /*
                  * part2
                */
                if (mouth.size() > 0) {  //if there is mouth, then
                    unsigned int real = 0;
                    for(unsigned int j = 0; j < mouth.size(); ++j) {
                        if (mouth[real].y < mouth[j].y) { real = j;}
                    }
                    /*
                      * part3
                    */
                    Rect m = mouth[real];
                    if (mouth[real].y > F_ROI.rows/2) {
                        Mat M_ROI = F_ROI(GetAdjRect(F_ROI, m, REST));
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
//setMouthData2 - adjust images
Rect GetContourArea(vector <Point2f> &_fl)
{
    int idx = _fl.size() > 0? _fl.size()-NUM_LANDMARK : 0;
    float lx = _fl[idx+48].x - (_fl[idx+48].x - _fl[idx+5].x)/2,
        ly =_fl[idx+51].y - (_fl[idx+51].y - _fl[idx+33].y)/2,
        rx =_fl[idx+54].x + (_fl[idx+11].x - _fl[idx+54].x)/2,
        ry=_fl[idx+57].y + (_fl[idx+8].y - _fl[idx+57].y)/3;
    Rect res(Point(lx, ly), Point(rx, ry));
    return res;
}
//setMouthData1 - adjust images
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
//Save point of landmark
void writeMouthXY(vector <Point2f> &_mouthland, bool _force)
{
    if (_force || _mouthland.size()/NUM_LANDMARK >= MAX_MOUTH_CNT) {
        cout << " > mouth_xy is reporting.." << endl;
        ofstream mlm_ifs(DST_IMG_PATH + DST_IMG_FOLDER[3] + TEXT_NAME[1], ofstream::app);
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
//Calculate some of statistics of source images
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

        if (frame.empty()) {
            cerr << " > img is missing" << endl;
            cerr << " >> not found :" <<  in_file.str() << endl;
            return -1;
        }

        vector<Rect_<int> > faces;
        detectFaces(frame, faces);
        //
        vector<Mat> mouth = GetMouthFromFaces(frame, faces);
        for (uint i=0; i<mouth.size(); ++i) {
            uint ma = mouth[i].rows*mouth[i].cols;
            m_sum += ma;//average
            ofs << ma << endl;
            total++;
            left++;
        }
        //to avoid overflow
        if (left % MAX_MOUTH_CNT == 0) {
            cout << "# round(" << (total/MAX_MOUTH_CNT) << ")" << endl;
            m_sum += avgMA*(total-MAX_MOUTH_CNT);
            avgMA = total > 0? m_sum/total : total;
            m_sum = left = 0;
        }
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
//find face from source image
void detectFaces(Mat& img, vector<Rect_<int> >& faces)
{
  if (!face_cascade.empty())
    face_cascade.detectMultiScale(img, faces, 1.15, 3, 0|CASCADE_SCALE_IMAGE, Size(30, 30));
  return;
}
//find mouth from source image
void detectMouth(Mat& img, vector<Rect_<int> >& mouth)
{
    if (!mouth_cascade.empty())
        mouth_cascade.detectMultiScale(img, mouth, 1.20, 5, 0|CASCADE_SCALE_IMAGE, Size(30, 30));
    return;
}
