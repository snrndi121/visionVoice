#include <opencv2/opencv.hpp>
#include <opencv2/face.hpp>
#include "drawLandmarks.hpp"
#include "visionVoice.hpp"

#include <fstream>
#include <time.h>
#include <vector>

using namespace std;
using namespace cv;
using namespace cv::face;

//
void makeSignalFile(const vector < pair_float > _talksession);
// void printMotherword(vector < MouthFeature >  src);
//
void saveRegion(ofstream& ofs, float _in);
void saveRegionVector(ofstream& ofs, vector < pair_float > _src);
void saveFilteredRegionVector(ofstream& ofs, vector < pair_float > _src);
void saveRegionVectorAll(vector < pair_float > _inner_total, vector < pair_float > _outer_total);

#define MAX_MOTHER_WORD_SAMPLE 120
#define MIN_TALK_RESPONSE 2
int main(int argc, char** argv)
{
    if (argc < 2) {
        cout << "video file not found" << endl;
        return -1;
    }
    // 얼굴 검출기 로드
    CascadeClassifier faceDetector("/usr/local/share/opencv4/haarcascades/haarcascade_frontalface_alt2.xml");
    // 얼굴 랜드마크 변수 생성
    Ptr<Facemark> facemark = FacemarkLBF::create();
    // 얼굴 랜드마크에 lbd 모델 로드
    facemark->loadModel("./lbfmodel.yaml");
    // facemark->loadModel("./AAM.yaml");
    // 출력할 비디오 준비
    VideoCapture cam(argv[1]);
    // 비디오 관련 변수 설정
    // cam.set(CAP_PROP_FRAME_WIDTH, 640);
    // cam.set(CAP_PROP_FRAME_HEIGHT, 480);
    double fps = cam.get(CAP_PROP_FPS);
    cout << "FPS : " << fps << endl;
    int delay = cvRound(1000 / fps);
    // 비디오 프레임 저장 변수
    Mat frame, gray;
    //입술 객체, 입모양 객체 선언
    LipsArea lip;
    MouthTokenList mouth;
    clock_t start = clock();//동영상 기준 시작 시간
    //카메라 데이터 입력
    while(cam.read(frame))
    {
        static unsigned char sample_count = 0;
        float cur_time = 0;
        // 얼굴 영역 저장될 변수 선언
        vector<Rect> faces;
        //회전 변환 : 현재비디오 영역이 매칭이 안되서
        rotate(frame, frame, ROTATE_90_CLOCKWISE);
        // 현재 비디오 프레임을 gray로 변환함
        cvtColor(frame, gray, COLOR_BGR2GRAY);
        // 얼굴 탐지
        faceDetector.detectMultiScale(gray, faces);
        // 랜드마크가 저장될 공간
        vector< vector<Point2f> > landmarks;
        // 랜드마크 탐색기 수행
        bool success = facemark->fit(frame, faces, landmarks);
        if(success) {
            // 얼굴 랜드마크 내부에서 현재 시간과 입술 안쪽 계산해서
            // LipsArea 객체 정보 전달
            for(int i = 0; i < landmarks.size(); i++) {
                //입술 영역 그리기
                drawMouthContour(frame, landmarks[i]);
                clock_t end = clock();
                // cur_time = (end - start) * 1000 / CLOCKS_PER_SEC;
                cur_time = (end * 1000) / CLOCKS_PER_SEC;
                //화자분리 1단계. 입 열린지 판단
                lip.setLipsAreaDiff(cur_time, landmarks[i]);
                //화자분리 2단계. 모음 판단
                // mouthshape.push((end - start)/CLOCKS_PER_SEC, landmarks[i]);
            }
        }
        // 출력 : 종합 처리된 프레임 = 현재 화면 + 입술 외곽선
        imshow("Facial Landmark Detection", frame);
        // Exit loop if ESC is pressed
        if (waitKey(delay) == 27) {  break;}
    }
    //대화 객체 선언
    ConversationPoint cp;
    cp.setLipsArea(lip);//인식된 입술 객체 -> '대화' 객체로 할당
    // cp.setMouthShape(mouthshape);
    //출력 : 입술 객체 포인트
    // cout << "\n### save file ### " << endl;
    // ofstream ofs_inner("region_in.md");
    // saveRegionVector(ofs_inner, lip.getInnerDiff());
    // ofs_inner.close();
    //발화 시점 탐색
    cout << "\n### find talksession start ###" << endl;
    cp.findTalkSession();
    cout << "\n### find talksession end ###" << endl;
    //출력 : 발화 시점 출력
    makeSignalFile(cp.getTalkSession());
    return 0;
}

/*
  * 시그널 플롯 데이터로 추출
  * 구간 [start, end ]
*/
void makeSignalFile(const vector < pair_float > _talksession)
{
      ofstream ofs("talkSignal.md");
      for (uint i = 0; i < _talksession.size(); ++i) {
          float diff_time = _talksession[i].second - _talksession[i].first;
          if (diff_time / 1000 >= MIN_TALK_RESPONSE) {//일정 대답 길이 이상이라면
              ofs << _talksession[i].first << "," << _talksession[i].second << endl;
          }
      }
      ofs.close();
}
/*
  * 모음 데이터셋 추출
  * 48 ~ 67 번까지 특징점 추출
*/
// void printMotherword(vector < MouthFeature >  src) {
//     cout << "\n #### printMotherword ####" << endl;
//     ofstream ofs("mother_word.csv");
//     for (uint i = 0; i != src.size(); ++i) {
//         ofs <<  i << ' ';
//         vector < Point2f > features = src[i].getPoints();
//         for (uint j = 0; j < features.size(); ++j) {
//             ofs << features[j].x << ' ' << features[j].y << ' ';
//         }
//         ofs << endl;
//     }
//     ofs.close();
// }
/*
  *
*/
#define MAX_MEAN 100
#define ERROR_CODE -1
#define FILTER_FRAME 30
void filterRegionVector(vector < pair_float >& _src)
{
    //abnormal_value
    cout << "\n## Get rid of abnormal value" << endl;
    cout << "src_size :" << _src.size() << endl;
    for (vector < pair_float >::iterator it = _src.begin();
      it != _src.end(); ++it) {
          if (it->second > MAX_MEAN) {
              _src.erase(it);
          }
    }
    cout <<" >> filtering_src_size :" << _src.size() << endl;
    //sampling
    // cout << "\n## sampling start " << endl;
    // uint sample_count = 0;
    // vftype res;    float unit_diff = 0;
    // for (vftype::iterator it = _src.begin();
    //   it != _src.end(); ++it) {
    //       float represent_sum = *it;
    //       if (sample_count++ == FILTER_FRAME) {
    //           sample_count = 0;
    //           res.push_back(represent_sum/FILTER_FRAME);
    //       }
    // }
    // cout << "\n## sampling end " << endl;
    // return res;
}
void saveRegionVectorAll(vector < pair_float >& _inner_total, vector < pair_float >& _outer_total)
{
    uint inner_size = _inner_total.size(), outer_size = _outer_total.size();
    cout << "in_size : " << inner_size << ", out_size : " << outer_size << endl;
    //
    if (inner_size != outer_size) {
        cout << ">> sampleing 개수 일치 실패" << endl;
        ofstream ofs_inner("region_all.md");
        saveRegionVector(ofs_inner, _inner_total);
        ofs_inner.close();
        ofstream ofs_outer("region_outer.md");
        saveRegionVector(ofs_outer, _outer_total);
        ofs_outer.close();
        return;
    }
    cout << " >> sampling 개수 일치 성공" << endl;
    filterRegionVector(_inner_total);
    filterRegionVector(_outer_total);
    ofstream ofs_all("all.md");
    for (uint i = 1; i < inner_size; ++i) {
        ofs_all << '[' << i << ", " << _inner_total[i].second <<", " << _outer_total[i].second << "],\n";
    }
}
void saveRegionVector(ofstream& ofs, vector < pair_float > _in_total)
{
    filterRegionVector(_in_total);
    for (uint r_index = 0; r_index < _in_total.size(); ++r_index)
    {
        ofs << '[' << (r_index + 1) << ", " << _in_total[r_index].second << "],\n";
    }
}
void saveFilteredRegionVector(ofstream& ofs, vector < pair_float > _in_total)
{
    filterRegionVector(_in_total);
    for (uint r_index = 0; r_index < _in_total.size(); ++r_index)
    {
        ofs << '[' << (r_index + 1) << ", " << _in_total[r_index].second << "],\n";
    }
}
void saveRegion(ofstream& ofs, float _in)
{
    static int r_index = 0;
    ofs << '[' << r_index << ", " << _in << "],\n";
}
