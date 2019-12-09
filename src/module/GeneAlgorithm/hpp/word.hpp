#ifndef _WORD_H_
#define _WORD_H_

//각 모음과 매트릭스 내 위치를 저장
typedef struct WordNode {
    Mother_Word code;
    int index = -1;
}WordNode;

//모음 정보들이 모인 리스트(하나의 문장)
class WordList {
public :
    WordList(){}
    WordList(string, float s = 0, float e = 0);
    //method
    void add(char c, int i = -1);
    //set
    void setLap(float, float);
    void setScore(float);
    //get
    string getSentence() const;
    float getLapTime() const;
    float getStartTime() const;
    float getEndTime() const;
private :
    WordNode makeWord(char c, int i = -1);
    //var
    float startTime = 0, endTime = 0;//발화 문장의 시작, 끝
    float score = 0;//발화 문장에 대한 점수
    vector < WordNode > sentence;//발화 문장
};
//아직 미사용 -> '패턴 탐색'시 사용 예정
//중심 문장(origin)에 대하여 생성될 수 있는 조합쌍을 저장
typedef struct WordCandidate {
    WordCandidate(){};
    string origin;//중심 문장
    string biased_origin;//실제 발견된 중심 문장
    vector < WordList > candidates;//origin에서 파생될 수 있는 발화 문장 조합
    // void add(WordList);
    // void setRepresent(string);
}WordCandidate;
#endif

#ifndef _WORD_CPP_
#define _WORD_CPP_

#include "word.cpp"

#endif
