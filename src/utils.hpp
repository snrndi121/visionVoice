#ifndef _utils_H_
#define _utils_H_

const string IN_FILE_PATH = "./"
const string OUT_FILE_PATH = "./"
const string FILE_TYPE = '.mp4';
void makeFramesFrom(VideoCapture& src, string out_file_name)
{
    if (!src.isOpened()) {
        cerr << ">> 일하는 비디오를 찾지 못 하였습니다." << endl
        return ;
    }
    //fat-cnn
    double fps = cap.get(CAP_PROP_FPS);
    cout << "FPS : " << fps << endl;

    int delay = cvRound(1000 / fps);
    cout << "Delay : " << delay << endl;
    Mat frame;
    //데이터 열기
    while (true) {
        src >> outNames;
        FILE_PATH += (OUT_FILE_PATH + out_file_name ) + FILE_TYPE;
        cout << " current_path "<< FILE_PATH << endl;

        
    }

}
#end if
