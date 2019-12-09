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
    void addSession(TalkSession);
    //set
    void setLapTime(float);
    void setFullTalk(WordList);
    //get
    float getLapTime() const;
    WordList getFullTalk() const;
    unsigned int getSessionCount() const;
    vector < TalkSession > getTalkSession() const;
private :
    float laptime = 0;
    WordList fullConversation;//대화 전문
    vector < TalkSession > eachConversation;//대화를 구성하는 발화자의 정보
};
#endif
#ifndef _TALK_CPP_
#define _TALK_CPP_

#include "talk.cpp"
#endif
