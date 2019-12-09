#ifndef _MOTHER_WORD_H_
#define _MOTHER_WORD_H_

using namespace std;

#include <cstdlib>
#include <time.h>

char ERR_CVT_CODE = '*';
#define NUM_MOTHER 8
//입술 모양이 한번 변하는 모음
enum Mother_Word {
   SHAPE_NONE = '0',  //입 다문 상태, , {}
   SHAPE_A = '1', //'아'발음, , {}
   SHAPE_EU = '2',//'어'발음, , {}
   SHAPE_O = '3',//'오'발음, , {}
   SHAPE_U = '4',//'우'발음, , {'유'}
   SHAPE_UI = '5',//'으'발음, , {'의'}
   SHAPE_I = '6',//'이'발음, , {}
   SHAPE_E = '7'//'에'발음, , {'애'}
};
//입술 모양이 두번 이상 변하는 모음
#define NUM_STEP_MOTHER 7
enum StepMother_Word {
  SHAPE_IA = '8', //'야' 발음, '이' + '아', {}
  SHAPE_IEU = '9',//'여' 발음, '이' + '어', {}
  SHAPE_OE = 'A',//'외' 발음, '오' + '에', {'왜', '웨'}
  SHAPE_UEU = 'B',//'워' 발음, '우' + '어', {}
  SHAPE_IE = 'C',//'얘' 발음, '이' + '에', {}
  SHAPE_OA = 'D',//'와' 발음, '오' + '아', {}
  SHAPE_WE = 'E',//'위' 발음, '우' + '이', {}
  NOT_FOUND ='F'
};
//입술 모양 : string -> hex
struct cvtWordType {
    cvtWordType() {}
    cvtWordType(char c) {
        switch(c) {
            case SHAPE_NONE : {mother_word = SHAPE_NONE; break;}
            case SHAPE_A : {mother_word = SHAPE_A;break;}
            case SHAPE_EU : {mother_word = SHAPE_EU;break;}
            case SHAPE_O : {mother_word = SHAPE_O;break;}
            case SHAPE_U : {mother_word = SHAPE_U;break;}
            case SHAPE_UI : {mother_word = SHAPE_UI;break;}
            case SHAPE_I : {mother_word = SHAPE_I;break;}
            case SHAPE_E : {mother_word = SHAPE_E;break;}
            default :
              cerr << "struct cvtWordType.construction faild. The character can't be matched. or it's sort of stepmother.\n";
              break;
        }
    }
    //method
    const vector < string > stepTOMother = {"61", "62", "37", "42", "67", "31", "46"};
    char cvtStringToHex(string s) {
        char res = '*';
        if (s == "0") {res = SHAPE_NONE;}
        else if (s == "ㅏ") { res = SHAPE_A;}
        else if (s == "ㅓ") { res = SHAPE_EU;}
        else if (s == "ㅗ" || s == "ㅛ") { res = SHAPE_O;}
        else if (s == "ㅜ" || s == "ㅠ") { res = SHAPE_U;}
        else if (s == "ㅡ" || s == "ㅢ") { res = SHAPE_UI;}
        else if (s == "ㅣ") { res = SHAPE_I;}
        else if (s == "ㅔ" || s == "ㅐ") { res = SHAPE_E;}
        else if (s == "ㅑ" || "61") { res = SHAPE_IA;}
        else if (s == "ㅕ" || "62") { res = SHAPE_IEU;}
        else if (s == "ㅚ" || s == "ㅙ" || s == "ㅞ" || "37") { res = SHAPE_OE;}
        else if (s == "ㅝ" || "42") { res = SHAPE_UEU;}
        else if (s == "ㅒ" || "67") { res = SHAPE_IE;}
        else if (s == "ㅘ" || "31") { res = SHAPE_OA;}
        else if (s == "ㅟ" || "46") { res = SHAPE_WE;}
        else if (s == "F") { res = NOT_FOUND;}
        else { cout << ">> convert failed" << endl;}
        return res;
    }
    /*
    char cvtStringToHex(string s) {
        char temp_mw = mother_word, temp_smw = stepmother_word;
        if (s == "0") {mother_word = SHAPE_NONE;}
        else if (s == "ㅏ") { mother_word = SHAPE_A;}
        else if (s == "ㅓ") { mother_word = SHAPE_EU;}
        else if (s == "ㅗ" || s == "ㅛ") { mother_word = SHAPE_O;}
        else if (s == "ㅜ" || s == "ㅠ") { mother_word = SHAPE_U;}
        else if (s == "ㅡ" || s == "ㅢ") { mother_word = SHAPE_UI;}
        else if (s == "ㅣ") { mother_word = SHAPE_I;}
        else if (s == "ㅔ" || s == "ㅐ") { mother_word = SHAPE_E;}
        else if (s == "ㅑ" || "61") { smw = SHAPE_IA;}
        else if (s == "ㅕ" || "62") { stepmother_word = SHAPE_IEU;}
        else if (s == "ㅚ" || s == "ㅙ" || s == "ㅞ" || "37") { stepmother_word = SHAPE_OE;}
        else if (s == "ㅝ" || "42") { stepmother_word = SHAPE_UEU;}
        else if (s == "ㅒ" || "67") { stepmother_word = SHAPE_IE;}
        else if (s == "ㅘ" || "31") { stepmother_word = SHAPE_OA;}
        else if (s == "ㅟ" || "46") { stepmother_word = SHAPE_WE;}
        else if (s == "F") { stepmother_word = NOT_FOUND;}
        else { cout << ">> convert failed" << endl;}
    }
    */
    //Mother_Word로만 구성된 String에서 StepMother_Word로 변환 가능한 수를 찾아냄.
    vector < vector < int > > findStepFromMother(string _pure_mother) {
        cout << "#findStepFromMother start #" << endl;
        vector < vector < int > > res_matrix;
        //변환가능한 토큰 집합
        for (uint i = 0; i < stepTOMother.size(); ++i) {
              string temp_pure_mother = _pure_mother;
              uint cvtStepCount = 0;//Mother_word로만 구성된 문자열에서 stepTOMother[i]가 발견된 수
              uint find_pos = temp_pure_mother.find(stepTOMother[i]);
              vector < int > find_poss;//stepTOMother[i]가 발견된 지점
              while (find_pos != string::npos) {
                  cout << ">> temp_pure_mother : " << temp_pure_mother << endl;
                  cvtStepCount++;
                  find_poss.push_back(find_pos);
                  temp_pure_mother.erase(0, find_pos + 1);
                  find_pos = temp_pure_mother.find(stepTOMother[i]);
              }
              cout << " >> " << stepTOMother[i] << " is found : " << cvtStepCount << endl;
              res_matrix.push_back(find_poss);
        }
        cout << "#findStepFromMother end #" << endl;
        return res_matrix;
    }
    //Mother_Word 타입을 가능한 Step_Mother로 변환함
    //parameter 1 : Mother_word -> 16진수 변환된 스트림
    //parameter 2 : Mother_word 내에서 동시에 인식할 StepMother_Word 개수
    vector < string > cvtMotherToStep(string s, uint allowed_duplication) {
          vector < string > new_gen;//변환된 새 형태
          srand((unsigned)time(NULL));
          vector < vector < int > > stepCountMatrix = findStepFromMother(s);
          cout << "# cvtMotherToStep start #" << endl;
          for (uint i = 0; i < stepCountMatrix.size(); ++i) {
                string temp_str = s;
                bool* dup_pos = new bool[stepCountMatrix[i].size()];
                //랜던 인덱스 중복값 체크를 위한 변수, dup_pos
                for (uint i = 0; i < stepCountMatrix[i].size(); ++i ) { dup_pos[i] = false;}
                //변환 가능한 범위에서 무작위로 위치에 대한 변환 과정
                for (uint k = 0; k < allowed_duplication; ++k) {
                    uint j = rand() % stepCountMatrix[i].size();
                    dup_pos[j] = true;
                    //유효한 무작위인지 판단
                    if (!dup_pos[j]) {
                        char stoken = cvtStringToHex(stepTOMother[i]);
                        string str;
                        str.push_back(stoken);
                        new_gen.push_back(temp_str.replace(stepCountMatrix[i][j], 2, str));
                    }
                    if (k > stepCountMatrix[i].size()) break;
                }
          }
          cout << "# cvtMotherToStep end #" << endl;
          return new_gen;
    }
    void getClear() {
        Mother_Word mother_word = SHAPE_NONE;
        StepMother_Word stepmother_word = NOT_FOUND;
    }
    //스코어링에 상용됨
    //first : mother word 수
    //second : stepmother word 수
    pair <int, int > getScoredWord(string s) {
          uint mother_count = 0, step_count = 0;
          for (uint i = 0; i < s.size(); ++i) {
              //scoring
              if (s[i] < '8') {//아스키값 56 = '8'
                  mother_count++;
              } else {
                  step_count++;
              }
          }
          return make_pair(mother_count, step_count);
    }
    char getNumber() {
        if (mother_word!= SHAPE_NONE) { return mother_word;}
        else if (stepmother_word != NOT_FOUND) { return stepmother_word;}
        return ERR_CVT_CODE;
    }
    char c;
    Mother_Word mother_word = SHAPE_NONE;
    StepMother_Word stepmother_word = NOT_FOUND;
};
#endif
