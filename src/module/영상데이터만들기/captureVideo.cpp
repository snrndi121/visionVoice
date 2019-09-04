#include <opencv2/opencv.hpp>
#include <time.h>
#include <vector>
#include <iostream>

using namespace std;
using namespace cv;

const string FILE_NAME = "youtube_ibk_03";
const string VIDEO_TYPE = ".mp4";
const stinrg FILE_PATH = "./"
const string RES_FILE_PREFIX ="frames_";
void camera_in();
int main(int argc,char** argv)
{
    camera_in();
    return 0;
}
vector < pair <float, float> > talk_session;
void camera_in()
{
    sstream file_name;
    file_name << FILE_NAME << VIDEO_TYPE;
    VideoCapture cap(file_name.str();

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
    sstream res_file;
    res_file << RES_FILE_PREFIX << RES_FILE_PREFIX << FILE_NAME;
    //
    clock_t start = clock();
    Mat frame;
    while ( true ) {
        cap >> frame;
        clock_t end = clock();

        if (frame.empty()) {
            cout << " Frame is empty " << endl;
            break;
        }
        imshow("frame", frame);
        if (waitKey(delay) == 27) {
            break;
        }
    }
    destroyAllWindows();
}
