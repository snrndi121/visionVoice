#ifndef _TALK_H_
#define _TALK_H_

//한 명의 발화자가 생성하는 각 대화들을 저장
class TalkSession {
public :
    TalkSession(){};
    TalkSession(Speaker);
    ~TalkSession() {
        talkBundles.clear();
    }
    //method
    void addBundle(WordList);
    //set
    void setSpeaker(Speaker);
    void setLapTime(float);
    //get
    Speaker getSpeaker() const;
    float getLapTime() const;
    vector < WordList > getTalkBundles() const;
private :
    Speaker speaker;//발화자 정보
    vector < WordList > talkBundles;//발화자가 생성한 대화 뭉치
    float laptime = 0;//발화자의 총 발화 시간
};
//전체 대화 정보
class TalkHistory {
public :
    TalkHistory(){};
    ~TalkHistory() {
      eachConversation.clear();
    }
    //method
    void addSession(TalkSession);//발화 객체 추가
    //set
    void setLapTime(float);//전체 대화의 시간 설정
    void setFullTalk(WordList);//전체 대화문 설정
    //get
    float getLapTime() const;//전체 대화의 시간 반환
    WordList getFullTalk() const;///전체 대화문 반환
    unsigned int getSessionCount() const;//발화자 수 반환
    vector < TalkSession > getTalkSession() const;//발화 객체 반환
private :
    // void generateTiming();//전체 대화문에 대한 타이밍 구간 생성
    float laptime = 0;
    WordList fullConversation;//대화 전문
    vector < TalkSession > eachConversation;//대화를 구성하는 발화자의 정보
};
#endif
#ifndef _TALK_CPP_
#define _TALK_CPP_

#include "talk.cpp"
#endif
