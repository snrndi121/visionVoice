/*
  made by uki408
*/
#ifndef _seperateVoice_H_
#define _seperateVoice_H_

//1. library
#include <cmath>

//2. def
#define MAX_LIMIT_DIFF 2
#define MAX_SUSPICION_LEVEL 3

typedef pair <float, float> pair_float;
//3. var
/*
  ***** Class Lips *****
*/
class Lips
{
public :
    Lips() {};
    Lips(const vector < pair_float > src_inner, const vector < pair_float > src_outer) {
        diff_innerArea = src_inner;
        diff_outerArea = src_outer;
    }
    //set-get
    void setInnerLips(vector < pair_float > src) {
        diff_innerArea.clear();
        diff_innerArea = src;
    }
    void setOuterLips(vector < pair_float > src) {
        diff_outerArea.clear();
        diff_outerArea = src;
    }
    vector < pair_float > getInnerDiff() const { return diff_innerArea;}
    vector < pair_float > getOuterDiff() const { return diff_outerArea;}
    //method
    void setLipsDiff(vector < Point2f > &landmarks, float _timestamp, bool _inner);

private :
    vector < pair_float > diff_innerArea;//an are of inner lips, (timestamp, area)
    vector < pair_float > diff_outerArea;//an are of outer lips, (timestamp, area)
};
void Lips::setLipsDiff(vector < Point2f > &landmarks, float _timestamp, bool _isInner = true)
{
    //var
    static float pre_width = 0, pre_height = 0;
    float region_differ = 0 ;
    float after_width = abs(landmarks[64].x - landmarks[60].x),
          after_height = abs(landmarks[66].y - landmarks[62].y);
    //calculate diff_area
    vector < pair_float >& target = _isInner? diff_innerArea : diff_outerArea;
    if (pre_width != 0 || pre_height != 0) {
        region_differ = abs((after_height - pre_height)) * abs((after_width - pre_width));
        cout << " >> difference_region : " << region_differ << endl;
    }
    //result;
    target.push_back(make_pair(region_differ, _timestamp));
    pre_width = after_width;
    pre_height = after_height;
}
/*
  ***** Class ConversationPoint *****
*/
#ifndef MAX_INNER_LIBS_DIFF
#define MAX_INNER_LIBS_DIFF 100
#endif
struct SuspicionType
{
      enum SuspicionState
      {
        ZERO_STATE = 0 ,
        SUSPICIOUS = 1,
        PRIVISIONAL = 2,
        STEADY = 3,
      };
      SuspicionType() {}
      SuspicionState state = ZERO_STATE;
      uint stampIndex = -1;
};
class ConversationPoint
{
public :
    enum TalkState
    {
      //TALK_START,//deprecated because of duplication of TALK_ING's definition
      TALK_RESPONSE,//means "start",
      TALK_ING,//means "talkiMAX_SUSPICION_LEVELng"
      TALK_STOP,//means "listenning"
    };
    ConversationPoint() {};
    //set-get
    void setTalkSession(float _start, float _end) {
        talkingSession.push_back(make_pair(_start, _end));
    }
    void setLips(Lips _lips) { this-> byLipsOpen =_lips;}
    // void setMouth(Mouth _mouth) { this-> ByMouthMean =_mouth;}
    Lips getLips() const { return this->byLipsOpen;}
    vector < pair_float > getTalkSession() const { return talkingSession;}
    //method
    void filterLibs();
    void findTalkSession(bool _isInner);
    bool suspicion_handling(uint _timestamp);
private :
    Lips byLipsOpen;//solution1
    // Mouth ByMouthMean;//solution2
    vector < pair_float > talkingSession;
    ConversationPoint::TalkState tstate = TALK_STOP;
    /*
      * suspicion_flag
      * It handle two situation when it needs a judgement.
      * whether a conversation is start or not,
      * and is stopped or not
      *
      * parameter 1 : suspicion level
      * parameter 2 : an index of diff_'X'Area, X = {innder, outer}
    */
    vector < SuspicionType > suspicion_flag;//max size 3, which means each suspicious(100) -> provisional(110) -> steady(111)
};
// setTalkState, "판별 알고리즘" (judge_state)
/*
  * 현재 Talk_state에 따라서 처리 양상이 달라짐
  * case1. 말하지 않고 있었을 경우 (talk_state == TALK_STOP)
    * case1.1. src[i]가 기준 MAX_LIMIT_DIFF보다 커졌을 경우,
      -> 발화 시작한 것임.void
      -> talk_state -> TALK_RESPONSE 변경
    * case1.2. 그렇지 않다면 현상 유지
  * case2. 말을 갓 시작했을 경우 (talk_state == TALK_RESPONSE)
    * case2.1. src[i]가 기준 MAX_LIMIT_DIFF보다 커졌을 경우,
      -> 발화 중인 것으로 변경, talk_state -> TALK_TALKING
    * case2.2 src[i]가 기준 MAX_LIMIT_DIFF보다 작을 경우,
      -> suspicion 처리 {'네'라는 응답만 하고 끝난 상황인지, 발음상의 연음으로 변화가 없는 것인지, 실제로 그만둔 것인지}
  * case3. 말을 하는 도중이라면 (talk_state == TALK_ING)
    * case3.1. src[i]가 기준 MAX_LIMIT_DIFF보다 커졌을 경우,
      -> 현상 유지
    * case3.2. src[i]가 기준 MAX_LIMIT_DIFF보다 작아졌을 경우,
      -> suspicion 처리 {'네'라는 응답만 하고 끝난 상황인지, 발음상의 연음으로 변화가 없는 것인지, 실제로 그만둔 것인지}
*/
void ConversationPoint::filterLibs()
{
  ;
}
void ConversationPoint::findTalkSession(bool _isInner=true)
{
    vector < pair_float > src = _isInner? this->getLips().getInnerDiff() : this->getLips().getOuterDiff();
    for (uint i = 0; i < src.size(); ++i)
    {
      switch (this->tstate)
      {
        case TALK_STOP :
        {
          if (src[i].second > MAX_LIMIT_DIFF) {
            cout << ">> 말하기 시작!" << endl;
            this->tstate = TALK_RESPONSE;
          }
        }
        break;
        case TALK_RESPONSE :
        {
          static bool talk_on = false;
          if (src[i].second > MAX_LIMIT_DIFF) {
            if (!talk_on) {
              cout << ">> 말하는 중..." << endl;
              this->tstate = TALK_ING;
              talk_on != talk_on;
            }
          }
          else {
            bool judge = suspicion_handling(i);
            if (judge) {
              this->tstate = TALK_STOP;
              cout << ">> 대답만 했습니다." << endl;
            }
            //judge == true -> TALK_RESPONSE change To TALK_STOP
            //else, suspicious
          }
        }
        break;
        case TALK_ING :
        {
          if (src[i].second < MAX_LIMIT_DIFF) {
            suspicion_handling(i);
          }
          else {;}
        }
        break;
        default : break;
      }
    }
}
bool ConversationPoint::suspicion_handling(uint _stampindex)
{
    return true;
}
#endif
