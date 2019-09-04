#include <opencv2/opencv.hpp>
#include <time.h>
#include <vector>
#include <iostream>

using namespace std;
using namespace cv;

const string FILE_NAME = "uki_sample";
const string VIDEO_TYPE = ".avi";
const string FILE_PATH = "../샘플동영상파일/";
vector < clock_t > tlist;
void camera_in_video_out();
void time_out();
int main(int argc,char** argv)
{
    camera_in_video_out();
    time_out();
    return 0;
}
void camera_in_video_out()
{
    stringstream file_name;
    file_name << FILE_PATH << FILE_NAME << VIDEO_TYPE;
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        cerr << "Video open failed" << endl;
        return;
    }
    int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
    int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));
    double fps = cap.get(CAP_PROP_FPS);
    int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');
    int delay = cvRound(1000/fps);

    VideoWriter outputVideo(file_name.str(), fourcc, fps, Size(w, h));
    if(!outputVideo.isOpened()) {
        cout << "File open failed" << endl;
        return ;
    }
    Mat frame;
    clock_t start = clock();
    while (true) {
        cap >> frame;
        if (frame.empty()) {
            break;
        }
        outputVideo << frame;
        imshow("frame", frame);
        char wk = waitKey(delay);
        if (wk == 27) {
            break;
        } else if (wk == 's'){
            clock_t end = clock();
            cout << "end : " << (end * 1000)/CLOCKS_PER_SEC << endl;
            tlist.push_back(end);
        }
    }
    destroyAllWindows();
}
void time_out()
{
    char count = 0;
    ofstream ofs("sample_talksession_byself.md");
    cout << ">> tlist.size : " << tlist.size() << endl;
    for (uint i = 0; i < tlist.size(); ++i) {
        ofs << tlist[i] << " ";
        if (count++ == 2) {
            ofs << endl;
            count = count % 2;
        }
    }
    ofs.close();
}
