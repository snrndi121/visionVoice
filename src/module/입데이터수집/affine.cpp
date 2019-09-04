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

const string IMG_PREFIX = "ms_";
const string IMG_EXTENSION = ".png";
const string IMG_PATH = "./train_data/";
const string TRAIN_DATA_LIST = "./train_data_list.md";
const string AFFINE_TYPE[] = {"flip", "resize"};
/* file type */
enum IMG_TYPE {
    ORIGIN = 0,
    INVERSE = 1,
    GRAY = 2
};
const IMG_TYPE itype[3] = {IMG_TYPE::ORIGIN, IMG_TYPE::INVERSE, IMG_TYPE::GRAY};

void read_img();
Mat img_resize(Mat& src);
Mat img_afine_flip(Mat& src);
int main(int argc,char** argv)
{
    read_img();
    // string sample = "12_3.xml";
    // sample.insert(3,"_");
    // sample.insert(3, "mid");
    // sample.insert(0, IMG_PATH);
    // sample.replace(sample.size() - 4, 4, IMG_EXTENSION);
    // cout << sample << endl;
    return 0;
}

void read_img()
{
    // Mat img_resize = img_afine_resize(img);
    ifstream ifs(TRAIN_DATA_LIST);
    if (ifs.fail()) {
        cerr << " >> not found train_data_list " << endl;
        return ;
    }
    string file_name;
    while(ifs >> file_name) {
        string img_name = file_name;
        img_name.insert(0, IMG_PATH);
        img_name.replace(img_name.size() - 4, 4, IMG_EXTENSION);
        Mat src = imread(img_name);
        if (src.empty()) {
            cerr << ">> souce image is empty" << endl;
            break;
        }
        // cout << "src : " << img_name << endl;
        Mat img_flip = img_afine_flip(src);
        //set file_name
        img_name.insert(16, "_");
        string flip_file_name = img_name.insert(16, AFFINE_TYPE[0]);
        cout << " > dst : " <<  flip_file_name << endl;
        imwrite(flip_file_name, img_flip);
    }
}
Mat img_afine_resize(Mat& src)
{
    Mat dst;
    resize(src, dst, Size(640, 480), 0, 0, INTER_LINEAR);
    return dst;
}
Mat img_afine_flip(Mat& src)
{
    Mat dst;
    //flip - 3번째 파라미터 의미 1 : 좌우 대칭, 0 : 상하 대칭, -1 : 상하 좌우 대칭
    flip(src, dst, 1);
    return dst;
}
