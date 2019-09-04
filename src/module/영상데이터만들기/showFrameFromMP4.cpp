#include <opencv2/opencv.hpp>
#include <time.h>
#include <vector>

using namespace std;
using namespace cv;

const string f_path = "./frames/";

void camera_in();
int main(int argc,char** argv)
{
    camera_in();
    return 0;
}
void camera_in()
{
    static uint index = 0;
    VideoCapture cap("../샘플동영상파일/sample2/uki_sample.avi");
    // cout << "Frame width : " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
    // cout << "Frame height : " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;
    // cout << "Frame count : " << cvRound(cap.get(CAP_PROP_FRAME_COUNT)) << endl;
    if (!cap.isOpened()) {
        cerr << "Video open failed" << endl;
        return;
    }
    double fps = cap.get(CAP_PROP_FPS);
    // cout << "FPS : " << fps << endl;
    int delay = cvRound(1000 / fps);
    // cout << "Delay : " << delay << endl;
    Mat frame;
    while ( true ) {
        cap >> frame;
        if (frame.empty()) {
            cout << " Frame is empty " << endl;
            break;
        }
        imshow("frame", frame);
        //영상으로부터 프레임 저장
        stringstream file_name;
        file_name << f_path << "frame" << "_" << index++ << ".png";
        imwrite(file_name.str(), frame);
        if (waitKey(30) == 27) {
            break;
        }
    }
    destroyAllWindows();
}
