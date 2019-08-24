//1. 사진 읽고
//2. 색반전
//3. 흑백 (명암비 p208)
//4. 소밸 에지 (p315)
//5. 행령 노말라이즈 (p190)

//6. 파일 입출력 (p174)
#include <opencv2/opencv.hpp>
#include <opencv2/face.hpp>

#include <fstream>
#include <vector>

using namespace std;
using namespace cv;
using namespace cv::face;

const string IMG_INDEX_START = 0;
const string IMG_PREFIX = "ms_";
const string IMG_EXTENSION = ".png";
const string IMG_PATH = "./train_data/";
/* file type */
enum IMG_TYPE {
    ORIGIN = 0,
    INVERSE = 1,
    GRAY = 2
};
const IMG_TYPE itype[3] = {IMG_TYPE::ORIGIN, IMG_TYPE::INVERSE, IMG_TYPE::GRAY};

void camera_in();
void saveImg(Mat &img, IMG_TYPE img_type);
int main(int argc,char** argv)
{
    camera_in();
    return 0;
}

void camera_in()
{
    VideoCapture cap(0);

    if(!cap.isOpened()) {
        cerr << "Camera open failed" << endl;
        return;
    }
    // cout << "Frame width : " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
    // cout << "Frame height : " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;
    cap.set(CAP_PROP_FRAME_WIDTH, 640);
    cap.set(CAP_PROP_FRAME_HEIGHT, 480);

    Mat frame, inverse, gray;
    while(true) {
        //get frame;
        cap >> frame;
        if (frame.empty()) {
            break;
        }
        //preprossed-img
        inverse = ~frame;
        cvtColor(frame, gray, COLOR_BGR2GRAY);
        //print image
        imshow("inversed", gray);
        //wait user event
        char waitkey = waitKey(10);
        if(waitkey == 27) break;
        else if(waitkey == 's') {
            cout << " >> save current" << endl;
            saveImg(frame, itype[0]);
            saveImg(inverse, itype[1]);
            saveImg(gray, itype[2]);
        }
        else{;}
    }
    return ;
}
//이미지 데이터 저장 (save image data);
void saveImg(Mat &img, IMG_TYPE img_type)
{
    //declare
    static int count_orgin = IMG_INDEX_START;//img_count's variables
    static int count_inverse = IMG_INDEX_START;
    static int count_gray = IMG_INDEX_START;
    //part1. set file_name : mid_fix + post_fix & save parameters
    int* file_postfix = 0;
    string file_midfix = "";
    switch (img_type) {
        case IMG_TYPE::ORIGIN :
          file_postfix = &count_orgin;
          file_midfix = "origin_";
          break;
        case IMG_TYPE::INVERSE :
          file_postfix = &count_inverse;
          file_midfix = "inverse_";
          break;
        case IMG_TYPE::GRAY :
          file_postfix = &count_gray;
          file_midfix = "gray_";
          break;
        default :
          break;
    }
    //part1. set file_name : total
    stringstream ss_filename;
    ss_filename << IMG_PATH <<  IMG_PREFIX << file_midfix << (*file_postfix)++ << IMG_EXTENSION;
    string file_name = ss_filename.str();
    cout << " >filename : " <<  file_name << endl;
    //part2. ofstream
    imwrite(file_name, img);
}
