#include <opencv2/opencv.hpp>
#include <time.h>
#include <vector>

using namespace std;
using namespace cv;

const string VIDEO_KB_01 = "youtube_kb_01.mp4";

void camera_in();
int main(int argc,char** argv)
{
    camera_in();
    return 0;
}
void camera_in()
{
    VideoCapture cap(VIDEO_KB_01);

    if (!cap.isOpened()) {
        cerr << "Video open failed" << endl;
        return;
    }

    cout << "Frame width : " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
    cout << "Frame height : " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;
    cout << "Frame count : " << cvRound(cap.get(CAP_PROP_FRAME_COUNT)) << endl;

    double fps = cap.get(CAP_PROP_FPS);
    cout << "FPS : " << fps << endl;

    int delay = cvRound(1000 / fps);
    cout << "Delay : " << delay << endl;
    Mat frame;
    while ( true ) {
        cap >> frame;
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
