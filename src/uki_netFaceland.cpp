#include <opencv2/opencv.hpp>
#include <opencv2/face.hpp>
#include "drawLandmarks.hpp"
#include "seperateVoice.hpp"

#include <fstream>
#include <time.h>
#include <vector>

using namespace std;
using namespace cv;
using namespace cv::face;

void printMotherword(vector < MouthFeature >  src);
//
void saveRegion(ofstream& ofs, float _in);
void saveRegionVector(ofstream& ofs, vector < pair_float > _src);
void saveFilteredRegionVector(ofstream& ofs, vector < pair_float > _src);
void saveRegionVectorAll(vector < pair_float > _inner_total, vector < pair_float > _outer_total);

#define MAX_MOTHER_WORD_SAMPLE 120

int main(int argc,char** argv)
{
    // Load Face Detector
    CascadeClassifier faceDetector("/usr/local/share/opencv4/haarcascades/haarcascade_frontalface_alt2.xml");

    // Create an instance of Facemark
    Ptr<Facemark> facemark = FacemarkLBF::create();

    // Load landmark detector
    facemark->loadModel("./lbfmodel.yaml");

    // Set up webcam for video capture
    VideoCapture cam(0);
    cam.set(CAP_PROP_FRAME_WIDTH, 640);
    cam.set(CAP_PROP_FRAME_HEIGHT, 480);
    // Variable to store a video frame and its grayscale
    Mat frame, gray;

    //LipsArea
    LipsArea lip;
    MouthShape mouthshape;
    clock_t start = clock();
    // Read a frame
    while(cam.read(frame))
    {
        static unsigned char sample_count = 0;
        // Find face
        vector<Rect> faces;
        // Convert frame to grayscale because
        // faceDetector requires grayscale image.
        cvtColor(frame, gray, COLOR_BGR2GRAY);

        // Detect faces
        faceDetector.detectMultiScale(gray, faces);

        // Variable for landmarks.
        // Landmarks for one face is a vector of points
        // There can be more than one face in the image. Hence, we
        // use a vector of vector of points.
        vector< vector<Point2f> > landmarks;

        // Run landmark detector
        bool success = facemark->fit(frame, faces, landmarks);
        if(success)
        {
            // If successful, render the landmarks on the face
            for(int i = 0; i < landmarks.size(); i++)
            {
                drawMouthContour(frame, landmarks[i]);
                clock_t end = clock();
                //화자분리 1단계. 입 열린지 판단
                //lip.setLipsAreaDiff((end - start)/CLOCKS_PER_SEC, landmarks[i]);
                //화자분리 2단계. 모음 판단
                mouthshape.push((end - start)/CLOCKS_PER_SEC, landmarks[i]);
            }
        }
        // Display results
        imshow("Facial Landmark Detection", frame);
        // Exit loop if ESC is pressed
        if (waitKey(1) == 27) break;
        //Collect Data : sampling count
        if ((sample_count++) == MAX_MOTHER_WORD_SAMPLE) {
            cout << ">> 새로운 모음을 발음해주세요" << endl;
            while(1) {
                int waitInputKey = waitKey(1000);
                if (waitInputKey == 27) {;}
                else if(waitInputKey == 255) {;}
                else { cout << " >> Go" << endl; sample_count = 0; break;}
            }
        }
    }
    printMotherword(mouthshape.getMouthShapes());
    // ConversationPoint cp;
    // cp.setLipsArea(lip);
    // cp.setMouthShape(mouthshape);
    //file streamx
    // cout << "\n### save file ### " << endl;
    // ofstream ofs_inner("region_in.md");
    // saveRegionVector(ofs_inner, lip.getInnerDiff());
    // ofs_inner.close();
    // //find talk_session
    // cout << "\n### find talksession ###" << endl;
    // cp.findTalkSession();
    return 0;
}

/*
  * 모음 데이터셋 추출
  * 48 ~ 67 번까지 특징점 추출
*/
void printMotherword(vector < MouthFeature >  src) {
    cout << "\n #### printMotherword ####" << endl;
    ofstream ofs("mother_word.csv");
    for (uint i = 0; i != src.size(); ++i) {
        ofs <<  i << ' ';
        vector < Point2f > features = src[i].getPoints();
        for (uint j = 0; j < features.size(); ++j) {
            ofs << features[j].x << ' ' << features[j].y << ' ';
        }
        ofs << endl;
    }
    ofs.close();
}
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
