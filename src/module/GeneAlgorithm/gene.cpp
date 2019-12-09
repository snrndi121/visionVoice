#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

#include "./hpp/gene.hpp"
/*
  * Variation
*/
vec_str full_digit;//GO(전체 문자)
vector < vec_str > target_digit;//Gx(타겟 문자)
map < char, vec_uint > markerMemory;//G0의 각 문자 분포도(markerMemory)
vector < vec_pair_str > search_result;
TalkHistory talkHistory;//발화 정보
/*
  * Function
*/
void input_gene();
void process_gene();
float gene_scoring(string);
void getCharMatrix(string&, string&);
void output_gene();
void print_global_constant();
int main()
{
    input_gene();
    process_gene();
    print_global_constant();
    output_gene();
    return 0;
}
void input_gene()
{
    cout << "\n# function_input_gene is on # \n";
    //파일 입력
    ifstream ifs("input.md");
    if (ifs.fail()) {
        cerr << ": no such file in this directory" << endl;
        return;
    }
    //변수 선언
    uint numOfTalker, numOfSentences;//전체 발화자 수, 발화자가 생성한 문장 수
    string in_full_str, in_target_str;//전체 모음 문자열, 각 발화자의 모음 문자열
    unsigned int talkerId;//발화자의 고유 식별값
    float full_time, start_time, end_time;//총 발화 시간, 각 발화자의 시작 및 종료 시간
    //입력
    ifs >> in_full_str >> numOfTalker >> full_time;
    WordList full_str(in_full_str);
    talkHistory.setFullTalk(full_str);
    talkHistory.setLapTime(full_time);
    //
    for (uint i = 0; i < numOfTalker; i++) {
        ifs >> talkerId >> numOfSentences;
        /**************** 발화자 초기화 ****************/
        Speaker speaker(talkerId);
        TalkSession talksession(speaker);
        /************* 발화자 문장 입력 **************/
        for (uint j = 0; j < numOfSentences; j++) {
            ifs >> in_target_str >> start_time >> end_time;
            WordList wordlist(in_target_str, start_time, end_time);
            talksession.addBundle(wordlist);
        }
        /************* 발화 정보 기록 **************/
        talkHistory.addSession(talksession);
    }
}
//하나의 G0에 대하여 다수의 GX의 탐색(1:M)
void process_gene()
{
    cout << "\n# function_process_gene is on # \n";
    /*
      * 1.인덱스 매트릭스 생성
    */
    //G0의 각 문자에 대한 인덱스 매트릭스
    for (uint i = 0; i < target_digit.size(); ++i)
        for (uint j = 0; j < target_digit[i].size(); ++j)
          getCharMatrix(full_digit[0], target_digit[i][j]);
    /*
      * 2.초기 패턴 트리 생성
    */
    //while (Gx 리스트)
    //특정 타이밍 구간 설정
    //현재 문자열에 대하여 매트릭스를 보면서 "일치&불일치" 탐색을 하며 WordCandidate 생성
    //결과 :
    /*
      * 3.패턴 트리 스코어링
    */
    //
    //
    /*
      * 4.초기 세대 선택
      *
      * 찾고자하는 타겟(Gx)를 실제 G0에서 찾은 제일 유사한 녀석을 초기 세대로 설정
    */
    /* 형제세대 생성
    //룰렛 휠
    */
    /*
    vec_pair_str eachResult;
    //
    for (uint i = 0; i < target_digit.size(); ++i) {
        uint gen_count = 0;
        boolean continueCycle = true;

        //각 Gx에 대한 형제 생성
        //pair < string, float >가 의미하는 것은, (형성된 문자열 패턴 형태, 스코어)
        vector < pair < string, float > > GxParent = FirstGeneration(target_digit[i]);//second 값은 NULL

        //GxParent의 자식 세대 생성
        while (continueCycle) {
            vector < pair < string, float > > GxChild;//자식 세대 선언
            //parent = 4, child = 0

            //part1. 스코어링 및 룰렛휠
            Rollette_Wheel(GxParent);//second 값 채워짐
            //parent = 2, child = 0

            //part2. 자식 세대 생성
            GxChild = generateChild(GxParent);
            //parent = 2, child = 4

            //part3. 돌연변이 생성
            MutateChild(GxChild);
            //parent = 2, child = 4

            //part4. 스코어링 및 룰렛휠
            Rollette_Wheel(GxChild);
            //parent = 2, child = 2

            //part5. 다음 부모 세대 재정의
            GxParent.clear();
            GxParent = GxChild;
            //parent = 0, child = 2

            //part6. base 확인
            continueCycle = (gen_count++ < MAX_GENE_CYCLE);//res.second < ?;어느 정도가 bestFitScore 인지 모름.
        }
        eachResult.push_back(make_pair(target_digit[i] , GxParent[0]));//제일 최적의 값
    }
    search_result.push_back(eachResult);
    */
}
//유전알고리즘-스코어링
/*
  * G0의 각 문자 분포도(markerMemory)에 의한 점수 계산을 할 것임
  * 계산 요소 : 각 인덱스간의 거리 & 구성 노드 개수
  * (예시)
  * 타겟 : 134
  * 인덱스 위치 : 1-> 4, 3 -> 10, 4 -> 15
  * 식 = 발견 노드수(3) * 5 - 거리 가중치 {(10-6) * 0.0.1 + (15-10) * 0.01}
       = 15 -(0.04 + 0.05) = 14.91
       => 14.91 * 발견된 위치에 따른 가중치(found_location(x))
*/
float gene_scoring(string _digit)
{
    cout << "\n# function_gene_scoring is on # \n";
    /* ver1.2
      * ver1.0의 found_location(x)의 의미를 다시 복귀
      * Score(Gx) = how_sequential(x) * found_location(x),
      * how_sequential(x) = correct_word(a) * 5 - sigma{distance(i, i+1) * 0.01, i = 0, 1, 2, k}
      * found_location(Gx) = n / (found_index - current_search_index),
      *
      * 변경된 이유
      * 전체 문자열(G0)에서 점수가 유사하게 나타나는 문자열이 등장할 것이기때문에 이에 따른 가중치를
        크게 주지 않으면 최적합에 이를 수 없을 것임.
    */
    /*
      * ver1.1
      * Score(x) = correct_word(a) * 5 - sigma{distance(i, i+1) * 0.01, i = 0, 1, 2, k}
      * 가점 방식 : 찾는 문자열(노드)의 수에 따라서 5점씩 가점
      * 가점 방식 : 찾는 문자열 간 거리에 따라서 0.01%씩 감점
      *
      * 참고
      * part1. 감점 방식 = 서로 인접한 경우를 더 최적(best fit)으로 판정할 것임
      * 3개의 노드가 있을 때
      * case1) 1.....3.....2......5 : 균등하게 분포된 경우
      * case2) 1.3.2..............5 : 서로 간에 인전한 경우
      *
      * 따라서, 전체 1 ~ 5의 거리는 같을 지라도 얼마나 인접한 지에 따라서 감점을 할 계획.
      * (Todo) 물론, 이 알고리즘에 있어서 보완책이 필요함
      *
      * 생각하게 된 계기
      *  - 탐색 방법을 고려할 때, 이진탐색을 고려하였음. 다음 노드를 선택함에 있어 조부모와 손자 간의
          중앙값에 가까울 수록 최적이라는 결론을 초기에는 고안하였으나, 감점 산정 방식에 따라서 최적의
          해를 찾지 못 하게 될 것이라고 판단함. 우의 "1325"의 경우, case1이 최적이라고 판단할 것을
          우려함.
    */
    /*
      * Score(Gx) = how_sequential(x) * found_location(x),
      * how_sequential(Gx) = correct_word(a) * 8 - wrong_word(n - a) * 2,
      * found_location(Gx) = n / (found_index - current_search_index),
      * n : 염색체 길이, a : GO에서 n 단위 탐색이 Gx와 일치한 문자열 개수
    */
    return 0;
}
//탐색
/*
  * how_sequential(Gx) = correct_word(a) * 8 - wrong_word(n - a) * 2,
  *
  * 기본
  * GX의 132 이를 G0에서 찾는 문제로부터, 사이즈 3 단위만 보는 것이 아니라 G0를 전역적으로 봐야될 것.
  *
  * 예제
  * 1 2 3 1 5 4 3 2 1 5 3 : G0
  * 1 3 2 : GX
  *
  * Step1) Gx의 digit 체크
  * * * * *     * * *   *
  * 1 2 3 1 5 4 3 2 1 5 3
  *
  * Step2) 연속적으로 나타날 수 없는 경우는 제거,
  *
  * *   * *     * * *   *
  * 1 2 3 1 5 4 3 2 1 5 3
  *
  * Step3) 거리에 따른 가중치 부여
  *
  * 점수 환산 방식 (임의)
  * Gx digit 발견시 : + 5
  * Gx digit 공백시 : - 1
  * 거리에 따른 감산 : - 0.1 %
*/
void getCharMatrix(string& _full_digit, string& _target_digit)
{
    cout << "\n > function_how_serquential is on.\n";
    //G0 내에서 GX 토큰 간의 일치도
    vec_uint bestFitIndexes = {0};//가장 최적합의 인덱스
    uint matchScore = 0;//매칭 점수
    if (_full_digit.size() <= 0) {
        cerr << "how_sequential() has a no valid full digit." << endl;
        return ;
    }
    //G0 내부의 문자 인덱스 정보 마킹
    const uint digit_size = _target_digit.size();
    for (uint i = 0; i < _target_digit.size(); ++i) {
        //G0 내부 문자 인덱스 정보 탐색&추가
        vec_uint markerList;//단일 문자에 대한 인덱스 정보를 저장할 공간
        size_t m = _full_digit.find(_target_digit[i]);
        while (m != string::npos) {
          markerList.push_back(m);
          m = _full_digit.find(_target_digit[i], m + 1);
        }
        //중복 여부 확인->문자 인덱스 정보
        if (markerMemory.find(_target_digit[i]) == markerMemory.end())
            markerMemory.insert(make_pair(_target_digit[i], markerList));
    }
    //마킹 트리 생성
}
void output_gene()
{
    cout << "\n# function_output_gene is on # \n";
  ;
}
void print_global_constant()
{
    cout << "\n# function_print_global_constant is on # \n";
    cout << endl << " >> Input content " << endl;
    //전체 문장 확인
    cout << ">> 전체 발화 정보 :";
    cout << talkHistory.getFullTalk().getSentence() << endl;
    //발화자당 문장 정보 확인
    cout << ">> 참여자 수 : ";
    cout << talkHistory.getSessionCount() << endl;
    vector < TalkSession > ts = talkHistory.getTalkSession();
    for (vector <TalkSession>::iterator it = ts.begin(); it != ts.end(); ++it) {
        cout << " > id : " << it->getSpeaker().getId() << endl;
        cout << " > lap time : " << it->getLapTime() << endl;
        cout << " > wordlist \n";
        vector < WordList > wl = it->getTalkBundles();
        for (vector < WordList >::iterator it2 = wl.begin(); it2 != wl.end(); ++it2) {
            cout << " [" << it2->getStartTime() << ", " << it2->getEndTime() << "] " << it2->getSentence() << endl;
        }
    }
    // for (uint i = 0; i < full_digit.size(); ++i) {
    //     cout << ">> G0 : " << full_digit[i] << endl;
    //     for (uint j = 0; j < target_digit[i].size(); ++j) {
    //         cout << " >> Gx : " << target_digit[i][j] << endl;
    //     }
    // }
    cout << endl << " >> Input matrix " << endl;
    for (map < char, vec_uint >::iterator it = markerMemory.begin(); it != markerMemory.end(); ++it) {
        char key = it->first;
        cout << key << " has indexes :";
        for (vec_uint::iterator it2 = markerMemory[key].begin(); it2 != markerMemory[key].end(); ++it2) {
            cout << *it2 << " ";
        }
        cout << endl;
    }
    cout << endl << " >> Searching Result" << endl;
    for (uint i = 0; i < search_result.size(); ++i) {
        for (uint j = 0; j < search_result[i].size(); ++j) {
            cout << search_result[i][j].first <<"->" << search_result[i][j].second << endl;
        }
    }
}
