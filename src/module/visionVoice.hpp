/*
  made by uki408
*/
#ifndef _visionVoice_H_
#define _visionVoice_H_

//1. library
#include <cmath>
#include "motherword.hpp"

#define MAX_LIMIT_DIFF 5
#define MAX_SUSPICION_LEVEL 3

typedef pair <float, float> pair_float;
/*
  ***** Class LipsArea *****
*/
class LipsArea
{
public :
    LipsArea() {};
    LipsArea(const vector < pair_float > src_inner, const vector < pair_float > src_outer) {
        diff_innerArea = src_inner;
        diff_outerArea = src_outer;
    }
    //set-get
    void setInnerLipsArea(vector < pair_float > src) {
        diff_innerArea.clear();
        diff_innerArea = src;
    }
    void setOuterLipsArea(vector < pair_float > src) {
        diff_outerArea.clear();
        diff_outerArea = src;
    }
    vector < pair_float > getInnerDiff() const { return diff_innerArea;}
    vector < pair_float > getOuterDiff() const { return diff_outerArea;}
    //method
    void setLipsAreaDiff(float _timestamp, vector < Point2f > &landmarks, bool _inner);

private :
    vector < pair_float > diff_innerArea;//an are of inner lips, (timestamp, area)
    vector < pair_float > diff_outerArea;//an are of outer lips, (timestamp, area)
};
//입 안쪽선 넓이(rect) 변화량 계산
void LipsArea::setLipsAreaDiff(float _timestamp, vector < Point2f > &landmarks, bool _isInner = true)
{
    //이전 넓이값을 계산하기 위하여 이전의 가로, 세로 길이를 저장함.
    static float pre_width = 0, pre_height = 0;
    float region_differ = 0 ;
    float after_width = abs(landmarks[64].x - landmarks[60].x),
          after_height = abs(landmarks[66].y - landmarks[62].y);
    //넓이 차이 계산
    vector < pair_float >& target = _isInner? diff_innerArea : diff_outerArea;
    if (pre_width != 0 || pre_height != 0) {
        region_differ = abs((after_height - pre_height)) * abs((after_width - pre_width));
        cout << " >> difference_region : " << region_differ << endl;
    }
    //결과값 저장.
    target.push_back(make_pair(_timestamp, region_differ));
    pre_width = after_width;
    pre_height = after_height;
}
/*
  **** Class MouthShape *****
*/
#define MOUTH_FEATURE 20
#define FACEL_POINT 68
#define MOUTH_START 48
#define MOUTH_END 67

/* deprecated
typedef pair < float, vector < Point2f > > pair_sec_mouthFeatures;
struct MouthFeature
{
    MouthFeature(){};
    MouthFeature(float _timestamp, vector < Point2f > &landmarks) {
        if (landmarks.size() != FACEL_POINT) { cout << "MouthFeature::constructor failed\n";return;}
        vector <Point2f> mFeatures;
        for (uint i = 0; i < MOUTH_FEATURE; ++i) {
            mFeatures.push_back(landmarks[MOUTH_START + i]);
        }
        points = make_pair(_timestamp, mFeatures);
    }
    void push(float _timestamp, vector < Point2f > &landmarks) {
        if (landmarks.size() != FACEL_POINT) { cout << "MouthFeature::push(landmarks) error, landmarks size error.\n";return;}
        vector <Point2f> mFeatures;
        for (uint i = 0; i < MOUTH_FEATURE; ++i) {
            mFeatures.push_back(landmarks[MOUTH_START + i]);
        }
        points = make_pair(_timestamp, mFeatures);
    }
    vector < Point2f > getPoints() const { return points.second;}
    float getTimestamp() const { return points.first;}
    pair_sec_mouthFeatures getMouthFeature() const { return points;}
//var
    pair_sec_mouthFeatures points;
};
class MouthShape
{
public :
    MouthShape(){};
    void push(float _timestamp, vector < Point2f > &landmarks) {
        if (landmarks.size() != FACEL_POINT) { cout << "MouthShape::setPoints(landmarks) error, landmarks size error.\n"; return;}
        MouthFeature mf(_timestamp, landmarks);
        mouthshapes.push_back(mf);
    }
    vector < MouthFeature > getMouthShapes() const { return mouthshapes;}
private :
    vector < MouthFeature > mouthshapes;
};
*/
/*
  * Class MouthShape
*/
typedef vector < string > vector_string;
// MotherToken
// 역할 : 일련의 모음 타입들에 대하여 숫자 스트림화하여 객체로 저장함
// 예시
// 입력 : ["shape_a", "shape_eu", "shape_a", "shape_o", "shape_U", ]
// 출력(저장된 값) : "1234"
struct MotherToken
{
    MotherToken(){};
    MotherToken(string _frame_name, vector_string _token_list, float _time_stamp = 0) {
        this->frame_name =_frame_name;
        this->tokenStream =_token_list;
        this->time_stamp =_time_stamp;
    }
    void push(string _frame_name, const vector_string _motherWord_List) {
        this->frame_name =_frame_name;
        string ts = getNumericStream(_motherWord_List);
        tokenStream.push_back(ts);
    }
    //Class Mother_word 를 16진수로 변환
    string getNumericStream(vector_string _motherWord_List)  {
        stringstream res;
        for (vector_string::iterator it = _motherWord_List.begin(); it != _motherWord_List.end(); ++it) {
            char m = cvtToNumericElement(*it);
            if (m != NOT_FOUND) {
                res << m;
            }
        }
        cout << ">> MotherToken::getNumericStream :" << res.str() << endl;
        return res.str();
    }
    //
    char cvtToNumericElement(string _mother_word) {
        if (_mother_word == "shape_a") { return SHAPE_A;}
        else if (_mother_word == "shape_eu") { return SHAPE_EU;}
        else if (_mother_word == "shape_o") { return SHAPE_O;}
        else if (_mother_word == "shape_u") { return SHAPE_U;}
        else if (_mother_word == "shape_ui") { return SHAPE_UI;}
        else if (_mother_word == "shape_i") { return SHAPE_I;}
        else if (_mother_word == "shape_e") { return SHAPE_E;}
        else if (_mother_word == "shape_none") { return SHAPE_NONE;}
        return NOT_FOUND;
    }
    //get
    string getFrameName() const { return frame_name;}
    float getTimestamp() const { return time_stamp;}
    vector_string getTokenStream() const { return tokenStream;}
    //var
    string frame_name = "";
    float time_stamp = 0;
    vector_string tokenStream;
};
//MouthTokenList
// 역할 : 프레임별로 해석된 MotherToken 저장
// 출력(저장된 값) : "1234"-"012341"-"1235721341",,,
class MouthTokenList
{
public :
    MouthTokenList(){};
    void push(string _file_name, vector_string _motherTokens) {
        MotherToken mt;
        mt.push(_file_name, _motherTokens);
        tokenlist.push_back(mt);
    }
    vector < MotherToken > getMouthShapes() const { return tokenlist;}
private :
    vector < MotherToken > tokenlist;
};
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
      REALEASE = -1,
      ZERO_STATE = 0 ,
      SUSPICIOUS = 1,
      PROVISIONAL = 2,
      STEADY = 3,
    };
    SuspicionType() { this-> id_name = make_pair(0, REALEASE);};//ZERO_STATE);};
    void up(float _timestamp) {
        if (this->timestamp != 0) this->timestamp =_timestamp;
        switch (id_name.first) {//get state index
            case 0 :
              this->id_name.first++;
              this->id_name.second = SUSPICIOUS;
              break;
            case 1 :
              this->id_name.first++;
              this->id_name.second = PROVISIONAL;
              break;
            case 2 :
              this->id_name.first++;
              this->id_name.second = STEADY;
              break;
            default :
              break;
        }
    }
    void down() {
        //discount state level
        if (this->id_name.first > 0) {this->id_name.first--;}
        switch (id_name.first) {//get state index
            case 1 :
              clear();
              break;
            case 2 :
              setState(1, SUSPICIOUS);
              break;
            case 3 :
              setState(2, PROVISIONAL);
            default : break;//nothing excuted
        }
    }
    void setState(uint _sid, SuspicionType::SuspicionState _sname) {
        this->id_name.first =_sid;
        this->id_name.second =_sname;
    }
    void clear() {
        this->timestamp = -1;
        this->id_name = make_pair(0, REALEASE);
    }
    float timestamp = 0;
    pair < uint, SuspicionState > id_name;//state_id, state_name;
};
class ConversationPoint
{
public :
    enum TalkState
    {
      //TALK_START,//deprecated because of duplication of TALK_ING's definition
      TALK_RESPONSE,//means "start",
      TALK_ING,//means "talking"
      TALK_REST,//means "rest in talking"
      TALK_STOP,//means "listenning"
    };
    ConversationPoint() {};
    //set-get
    void setTalkSession(float _start, float _end) {
        talkingSession.push_back(make_pair(_start, _end));
    }
    void setLipsArea(LipsArea _lips) { this-> byLipsAreaOpen =_lips;}
    // void setMouthShape(MouthShape _mouth) { this-> byMouthShape =_mouth;}
    LipsArea getLipsArea() const { return this->byLipsAreaOpen;}
    // MouthShape getMouthArea() const { return this->byMouthShape;}
    vector < pair_float > getTalkSession() const { return talkingSession;}
    //solution1 - method
    void filterLibs();
    void findTalkSession(bool _isInner);
    bool suspicion_handling(bool _isOpenLipsArea, uint _timestamp);
    //solution2 - method

private :
    LipsArea byLipsAreaOpen;//solution1
    MouthTokenList byMouthShape;//solution2
    vector < pair_float > talkingSession;
    ConversationPoint::TalkState tstate = TALK_STOP;
    /*
      * suspicion_flag
      * 판단이 필요한 순간일 때, 두 가지 상황을 처리하기 위해서 사용함.
      * (1) 대화가 시작했는지 아닌지
      * (2) 대화가 중단되었는지 아닌진
      *
      * parameter 1 : 의심 단계 레벨
      * parameter 2 : an index of diff_'X'Area, X = {innder, outer}
    */
    SuspicionType suspicionStage;
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
//Batch processing
//전체 영상에 대한 자료가 다 들어온 이후로 배치 처리함.
void ConversationPoint::findTalkSession(bool _isInner=true)
{
    vector < pair_float > src = _isInner? this->getLipsArea().getInnerDiff() : this->getLipsArea().getOuterDiff();
    float talk_start = 0 , talk_end = 0;
    //find talk session
    for (uint i = 0; i < src.size(); ++i)
    {
        static bool talk_on = false;//말을 하고 있었는 지 판단
        bool isOpenLipsArea = src[i].second > MAX_LIMIT_DIFF;//평균 변화 이상일 시 입 열림으로 '의심'
        //'의심 처리'
        bool isSteady = suspicion_handling(isOpenLipsArea, src[i].first);
        switch (this->tstate)
        {
          case TALK_STOP :
          {
              if (isOpenLipsArea) {
                  talk_start = src[i].first;
                  cout << "\n(" << talk_start << ") : 말하기 시작" << endl;
                  this->tstate = TALK_RESPONSE;
              }
          }
              break;
          case TALK_RESPONSE :
          {
              if (isOpenLipsArea) {
                  if (!talk_on) {
                    cout << " ## 대답하는 중 ##" << endl;
                    this->tstate = TALK_ING;
                    talk_on != talk_on;
                  }
              }
              else {
                  //Is [ TALK_RESPONSE -> TALK_STOP ]?
                  if (isSteady) {
                      //suspicion property
                      talk_end = this->suspicionStage.timestamp;
                      cout << "(" << talk_end << ") : 대답만 했습니다." << endl;
                      this->suspicionStage.clear();
                      //talk property
                      this->tstate = TALK_STOP;
                      talk_on != talk_on;
                      this->talkingSession.push_back(make_pair(talk_start, talk_end));
                  }
                  //else, [ TALK_RESPONSE -> TALK_REST ]?
              }
          }
              break;
          case TALK_ING :
          {
              if (isOpenLipsArea) {
                  if (talk_on) {
                    cout << " ## 말하는 중 ## " << endl;
                    talk_on != talk_on;
                  }
              }
              else {
                  if (isSteady) {
                      //suspicion property
                      talk_end = this->suspicionStage.timestamp;
                      cout << "(" << talk_end << ") : 말하기 종료" << endl;
                      this->suspicionStage.clear();
                      //talk property
                      this->tstate = TALK_STOP;
                      talk_on != talk_on;
                      this->talkingSession.push_back(make_pair(talk_start, talk_end));
                  }
              }
          }
          break;
          default : break;
        }
    }
    cout << "(" << src[src.size() - 1].first << ") : 대화를 마칩니다." << endl;
}
//Part2. suspicion level up/down
/*
* '입을 열었다/닫았다'란 행위는 현재 tstate가 어떤가에 따라 다른 의미를 가짐
* 가령, 입을 열었다는 것은 말을 하고 있지 않을 때는, 말을 시작했고 다음 상태의 변환을 의심해야하지만,
이미 말을 하고 있었다면 상태 변환을 의미하지 않음.
반대로, 입을 닫았다는 것은 말을 하고 있을 때는 상태 변환을 의미하지만,
이미 말을 하고 있지 않다면, 상태변환을 의미하지 않는다.
* 다만, 상태 변환을 의미하지 않는다고 해서 아무 처리를 해주지 않으면 안된다.
왜냐하면 상태 변환을 의심할 때 의심 단계를 up()하게 되는데, 그 뒤에 앞서 말한 상태 변환을
하지 않아도 된다던 것이 의심 단계를 down()시키기 때문이다.
* 그러나 주의할 점은, TALK_STOP 단계에서의 변환이다.
왜냐하면, STOP에서 말을 한다고 판정을 내리는 부분은 수월하기 때문이다. 왜냐하면, RESPONSE
단계를 별도로 두고 있기 때문에 STOP ->RESPONSE로의 전환은 빠르되, RESPONSE->TALKING,
TALKING->STOP의 심사를 철저히 하는 것으로 대체할 수 있다고 생각했기 때문이다.
*/
//의심단계와 관련된 속성들을 처리하고, STEADY 상태면 true 반환
bool ConversationPoint::suspicion_handling(bool _isOpenLipsArea, uint _timestamp)
{
    //Part1. set initial suspicious talk_start or talk_end
    //의심된 첫 시점을 기록하는 작업이 이뤄짐.
    SuspicionType::SuspicionState cur_stateName = this->suspicionStage.id_name.second;
    if (cur_stateName == SuspicionType::SuspicionState::REALEASE) {
        this->suspicionStage.timestamp = _timestamp;
    }
    ConversationPoint::TalkState curTalkstate  = this->tstate;
    if (_isOpenLipsArea) {
        if (curTalkstate != TALK_STOP) {
            this->suspicionStage.down();
        }// if (curTalkstate == TALK_RESPONSE) { this->suspicionStage.down();} else if (curTalkstate == TALK_ING) { this->suspicionStage.down();}
        else {
            // this->suspicionStage.up(); => unnecessarry
        }
    } else {
        if (curTalkstate != TALK_STOP) {
            this->suspicionStage.up(_timestamp);
        }// if (curTalkstate == TALK_RESPONSE) {this->suspicionStage.up();}else if (curTalkstate == TALK_ING) {this->suspicionStage.up();}
        else {
            // this->suspicionStage.down(); => unnecessarry
        }
    }
    //Part3. check if the statge can be a next stage
    //의심->추정->확고의 마지막 상태일 때는 true를 반환함.
    return (cur_stateName== SuspicionType::SuspicionState::STEADY);
}
#endif
