#include <iostream>
#include <fstream>
#include <vector>
#include "../motherword.hpp"

using namespace std;

const string IN_FILE_CLS_IMAGES = "./classifiedImages.md";//분류된 이미지 정보
int main()
{

    /*
      * Prepocessing data
    */
    //part1. 이미지 -> 숫자 스트림화
    //input_data : classifiedImages.md
    //form : image_name, motherWord_type
    /*
      1.png,0
      2.png,0
      3.png,0
      4.png,shape_a
      5.png,shape_e
      6.png,shape_o
      7.png,shape_u
      ...
    */
    ifstream ifs(IN_FILE_CLS_IMAGES);
    if (!ifs.fail()) {
        cerr << ">> " << IN_FILE_CLS_IMAGES << " not found" << endl;
        return ;
    }
    string frame_info;
    while (ifs >> frame_info) {

    }
    //while (이미지 세션 수)
      //분류된 이미지를 읽음
      //이미지가 어떤 Type인지 판별한뒤
      //이미지 세션 토큰 스트림 에 해당 Type의 스트림 추가

      //세션이 변경되면, 현재 이미지 세션 토큰 스트림 초기화
    //결과 : [ {"11100", "12100"}, "123124", "43423",, ]

    //part2. 음성 -> 숫자 스트림화
      //인식된 음성에서 모음 추출
      //결과 : "12123920910001020301002030001203012031023010203102301203010"

    /*
      * Processing numric stream
    */
    //part3. 유전자 알고리즘
      //현재 ImageSessionToken[i]의 원소들이 voiceStream에 존재하는 지 확인.


}
