#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
/*
  * Defnition
*/
//def-gene
#ifndef __GENE_CONSTANT
#define __GENE_CONSTANT

#define MAX_GENE_GENERATION 4
#define GENE_MUTATION 0.1
#define MAX_GENE_CYCLE 100

#endif
//def-type
typedef vector < string > vec_str;
typedef vector < uint > vec_uint;
typedef pair < string, string > pair_str;
typedef vector < pair_str > vec_pair_str;
/*
  * Variation
*/
vec_str full_digit;//GO
vector < vec_str > target_digit;//Gx
map < char, vec_uint > markerMemory;//Gx'elements matrix
vector < vec_pair_str > search_result;
/*
  * Function
*/
void input_gene();
void process_gene();
float gene_scoring(string);
void how_sequential(string&, string&);
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
    uint test_count, target_count;//테스트 케이스 개수, 발화 스트링 개수
    string in_str;//입력용 문자
    //입력
    ifs >> test_count;
    for (uint i = 0; i < test_count; i++) {
        ifs >> target_count >> in_str;
        //테스트 케이스 세트 시작
        full_digit.push_back(in_str);//G0 설정
        vec_str in_vec_str;
        for (uint j = 0; j < target_count; j++) {
            ifs >> in_str;
            in_vec_str.push_back(in_str);
        }
        target_digit.push_back(in_vec_str);//Gx 설정
    }
}
void process_gene()
{
    cout << "\n# function_process_gene is on # \n";
    //unit_test
    for (uint i = 0; i < target_digit.size(); ++i)
        for (uint j = 0; j < target_digit[i].size(); ++j)
          how_sequential(full_digit[0], target_digit[i][j]);
    //초기 세대 생성
    //자식세대 생성
    //룰렛 휠
    /*
    vec_pair_str eachResult;
    //
    for (uint i = 0; i < target_digit.size(); ++i) {
        uint gen_count = 0;
        boolean continueCycle = true;

        //각 Gx에 대한 형제 생성
        vector < pair < string, float > > GxParent = FirstGeneration(target_digit[i]);//second 값은 NULL

        //GxParent의 자식 세대 생성
        while (continueCycle) {
            vector < pairt < string, float > > GxChild;//자식 세대 선언
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
            //parent = 2, child = 2

            //part6. base 확인
            continueCycle = (gen_count++ < MAX_GENE_CYCLE);//res.second < ?;어느 정도가 bestFitScore 인지 모름.
        }
        eachResult.push_back(make_pair(target_digit[i] , GxParent[0]));//제일 최적의 값
    }
    search_result.push_back(eachResult);
    */
}
//유전알고리즘-스코어링
float gene_scoring(string _digit)
{
    cout << "\n# function_gene_scoring is on # \n";
    /*
      * Score(Gx) = how_sequential(x) * found_location(x),
      * how_sequential(Gx) = correct_word(a) * 8 - wrong_word(n - a) * 2,
      * found_location(Gx) = n / (found_index - current_search_index),
      * n : 염색체 길이, a : GO에서 n 단위 탐색이 Gx와 일치한 문자열 개수
      return how_sequential(_digit) * found_location(_digit);
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
void how_sequential(string& _full_digit, string& _target_digit)
{
    cout << "\n > function_how_serquential is on.\n";
    //G0 내에서 GX 토큰 간의 일치도
    vec_uint bestFitIndexes = {0};//가장 최적합의 인덱스
    uint matchScore = 0;//매칭 점수
    if (_full_digit.size() <= 0) {
        cerr << "how_sequential() has a no valid full digit." << endl;
        return ;
    }
    //G0 내부의 문자열 마킹
    const int digit_size = _target_digit.size();
    // map < char, vec_uint > markerMemory;
    for (uint i = 0; i < _target_digit.size(); ++i) {
        vec_uint markerList;
        size_t m = _full_digit.find(_target_digit[i]);
        while (m != string::npos) {
            markerList.push_back(m);
            m = _full_digit.find(_target_digit[i], m + 1);
        }
        if (markerMemory.find(_target_digit[i]) == markerMemory.end()) {
            markerMemory.insert(make_pair(_target_digit[i], markerList));
        }
    }
    //마킹된 정보 조합
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
    for (uint i = 0; i < full_digit.size(); ++i) {
        cout << ">> G0 : " << full_digit[i] << endl;
        for (uint j = 0; j < target_digit[i].size(); ++j) {
            cout << " >> Gx : " << target_digit[i][j] << endl;
        }
    }
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
