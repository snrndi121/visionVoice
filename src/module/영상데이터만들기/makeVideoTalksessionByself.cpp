#include <opencv2/opencv.hpp>
#include <time.h>
#include <vector>
#include <iostream>

using namespace std;
using namespace cv;

const string FILE_NAME = "youtube_ibk_03";
const string VIDEO_TYPE = ".mp4";
const string FILE_PATH = "../샘플동영상파일/";
void camera_in();
int main(int argc,char** argv)
{
    camera_in();
    return 0;
}
vector < float > tlist;
void camera_in()
{
    stringstream file_name;
    file_name << FILE_PATH << FILE_NAME << VIDEO_TYPE;
    cout << file_name.str() << endl;
    VideoCapture cap(file_name.str());

    if (!cap.isOpened()) {
        cerr << "Video open failed" << endl;
        return;
    }
    //
    cout << "Frame width : " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
    cout << "Frame height : " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;
    cout << "Frame count : " << cvRound(cap.get(CAP_PROP_FRAME_COUNT)) << endl;

    double fps = cap.get(CAP_PROP_FPS);
    cout << "FPS : " << fps << endl;

    int delay = cvRound(1000 / fps);
    cout << "Delay : " << delay << endl;
    //
    char start_end = 0;
    clock_t start = clock();
    Mat frame;
    while ( true ) {
        cap >> frame;
        clock_t end = clock();
        if (frame.empty()) {
            cout << " Frame is empty " << endl;
            float cur_time = end/CLOCKS_PER_SEC;
            cout << " >> 총 실행 : " << cur_time<< endl;
            break;
        }
        imshow("frame", frame);
        if (waitKey(fps) == ' ') {
            tlist.push_back(end);
        }
        // if (waitKey(delay) == ' ') {
        //
        //     cout << end << "-" << end/CLOCKS_PER_SEC <<endl;
        // }
        // else if (waitKey(delay) == 27) {
        //     cout << " Frame is empty " << endl;
        //     float cur_time = end/CLOCKS_PER_SEC;
        //     cout << " >> 총시간 : " << cur_time<< endl;
        //     break;
        // }
    }
    int count = 0;
    for (uint i = 0; i < tlist.size(); ++i) {
        cout << tlist[i] << " ";
        if (count++ == 2) {
            cout << endl;
            count = count % 2;
        }
    }
    destroyAllWindows();
}
