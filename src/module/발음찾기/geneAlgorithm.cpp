#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include "../motherword.hpp"
using namespace std;
//
string speechOrigin_name = "./speech_mother_word_origin.md";
string frameOrigin_name = "mother_word.md";

//파일입력 변수
vector < string > file_input_fromVoice;
vector < string > file_input_fromFrame;
vector < u16string > file_input2;
vector < char16_t > file_input3;
//프레임 스트림화
vector < string > token_list;
//음성 스트림화
stringstream speechNumericStream;

// 숫자 스트림으로 전환
void cvtSpeechToStream();
void cvtFrameToStream();
void matchingStream();
// 유전 알고리즘
// 파트1.초기화
void FirstGeneration(string parent, vector < string >& _possible_first, const char length);
// 파트2.선택
vector < pair < int, int > >
GenerationScoring();//생성된 문자열에 점수매기기 : Mother_word의 개수로
void SelectionByScore(vector < pair < int, int > > generation, vector < string > speechstream);//점수로 주요 문자열 골라내기
/// 파트3.탐색
void FindTokenFromVoiceStream(vector < string > src, stringstream dst);
int main()
{
    cvtSpeechToStream();
    cvtFrameToStream();
    matchingStream();
    return 0;
}
void cvtSpeechToStream()
{
    ifstream ifs(speechOrigin_name);
    if (ifs.fail()) {
        cerr << speechOrigin_name << " not found" << endl;
        return;
    }
    string s;
    //음성-모음 입력
    while (ifs >> s) {file_input_fromVoice.push_back(s);}
    //음성-숫자스트림화
    for (uint i = 0; i < file_input_fromVoice.size(); ++i) {
        cvtWordType n(file_input_fromVoice[i]);
        speechNumericStream << n.getNumber();
    }
    //스트림화 확인
    cout << speechNumericStream.str() << endl;
    file_input.clear();
    ifs.close();
}
/* 미완성 */
void cvtFrameToStream()
{
    ifstream ifs(speechOrigin_name);
    if (ifs.fail()) {
        cerr << speechOrigin_name << " not found" << endl;
        return;
    }
    u16string u16_str ;
    char16_t c;
    string s;
    //음성-모음 입력
    while (ifs >> s) {
    }
    //음성-숫자스트림화
    for (uint i = 0; i < file_input.size(); ++i) {
        cvtWordType n;
        n.cvtStringToHex(file_input[i]);
        speechNumericStream << n.getNumber();
    }
    //스트림화 확인
    cout << speechNumericStream.str() << endl;
    token_list.push_back();
    //
    file_input.clear();
    ifs.close();
}
void matchingStream()
{
    const char child_num = 10;
    for (uint i = 0; i < token_list.size(); ++i) {
        //part1. 세대 생성
        vector < string > strGeneration;
        strGeneration.push_back(token_list[i]);
        FirstGeneration(s, strGeneration, child_num);
        //part2. 점수 매기기
        vector < pair < int, int > > score_gene;
        score_gene = GenerationScoring(strGeneration);
        //part3. 점수에 따른 선택
        SelectionByScore(score_gene, strGeneration);
        //part4. 점수가 높은 토큰 위주로 음성 스트림에서 탐색
        FindTokenFromVoiceStream(strGeneration, speechNumericStream);
    }
}
//첫번째 세대에서 가능한 조합 생성
void FirstGeneration(string parent, vector < string >& _possible_first, const char generation_depth)
{
    //변수 초기화
    uint count = 0;
    const uint hazard_parent = 7;//크로스 오버 기준점
    cvtWordType n;//StepMother_Word와 Mother_Word를 변환하기 위한 변수
    string origin_parent = parent;
    //parent에서 가능한 조합을 찾아냄.
    for (int i = 0; i < generation_depth; ++i) {
        //현재 Mother_word 값에서 만들수 있는 Step_word로 변환을 시도함.
        vector < string > possible_unit = n.cvtMotherToStep(parent, i);
        //변환된 값이 존재한다면, 1세대에 추가함.
        if (possible_unit.size() > 0) {
            for (int j = 0; j < possible_unit.size(); ++j) {
                _possible_first.push_back(possible_unit[i]);}
        }
        //변화된 값이 존재하지 않다면,
        else {
            count++;
            //기존의 parent에 대하여 더 이상 유의미한 결과가 나오지 않는다면 origin 변환
            //CrossOver : stepmother로 변경된 문자열을 새로운 기준점으로 잡고 변경 시작함.
            if (count > hazard_parent) {
                uint r = _possible_first.size();
                parent = _possible_first[rand() % r];
                count--;
            }
        }
    }
}
vector < pair < int, int > > GenerationScoring()
{
    vector < pair < int, int > > res;
    cvtWordType c;
    //점수 스코어링
    for (uint i=0; i < _possible_first.size(); ++i) {
        res.push_back(c.getScoredWord(_possible_first[i]));
    }
    return res;
}
void SelectionByScore(vector < pair < int, int > > generation, vector < string > speechstream)
{

}
void FindTokenFromVoiceStream(vector < string > src, stringstream dst)
{
    uint best_position;
    string dst_str = dst.str();
    for (vector < string >::iterator it = src.begin();
      it != src.end(); ++it) {
          //전체를 바로 비교하지 않고 토큰의 일부분을 전체와 맞춰보면서
          //제일 많이 같은 세대의 문자열을 찾음
          //찾은 위치가 선행할수록 best라고 판단함.
          for (uint i = 0; i < (*it).size(); ++i) {
                uint find_pos = dst_str.find(src[i].substr(0, i));

          }


      }
}
