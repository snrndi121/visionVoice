/*
  * 날짜 : 190415
  * 내용 : 긴 문자열에서 특정 문자열 찾기 (KMP, 아호코라식)
  * 특이사항
    1. 특정 문자열(S[i]) 간의 순차성
      - S[i+1]는 S[i]보다 나중에 생성된 값

  * 추후 특이사항
    1. 완벽히 일치하지 않는 타겟
      (1) 길이 일치
        - 내용이 다른 경우,

      (2) 내용 일치
        - 중간에 필요없는 문자(열)이 삽입된 경우,
*/
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

#define MAX_TEST_LEN 3000
#define HN_RANGE 16
#define MIN_HN_LEN 30
#define MAX_HN_LEN 50
#define MAX_HN_SIZE 10
#define AVG_HN_LEN MAX_TEST_LEN/MAX_HN_SIZE
#define PROCESS_TERM 5

//def
struct SType {//searchType
  SType(size_t _sz, char *_data) : sz(_sz) {
      data = new char[_sz];
      for (size_t i = 0; i < _sz; ++i) { data[i]=_data[i];}
  }
  friend ostream&
  operator<<(ostream& ost, const SType& s) {
      for (size_t i = 0; i < s.sz; ++i) { ost << s.data[i];}
      return ost;
  }
  ~SType() {
      cout << "\n##SType die :";
      cout << data << endl;
      delete data;
  }
  //var
  size_t sz = 0;
  char *data;
};
typedef pair < int, int > ptype;
typedef vector < int > vtype;
typedef vector < ptype > v_ptype;
typedef vector < vtype > v_vtype;
//var
char* input_src;
vector < SType > input_dst;
//
v_ptype res1, res2;
//func
void generate_TESTCASE_N();
void generate_Sn();
v_vtype find_KMP(const char*, vector < SType >&);
v_vtype find_AHO(const char*, vector < SType >&);
void print_TESTCASE_N(const v_ptype&);
void print_vtype(const vtype &);
int main()
{
    generate_TESTCASE_N();
    generate_Sn();
    for (int i = 0; i < input_dst.size(); ++i) { cout << input_dst[i].data << endl;}
    // find_KMP(src, dst);
    // res2 = find_AHO(src, dst);
    //
    // print_TESTCASE_N(res2);
    // print_TESTCASE_N(res1);
    return 0;
}
void generate_TESTCASE_N()
{
    cout << "#generate_TESTCASE_N ..";
    input_src = new char[MAX_TEST_LEN];
    srand(time(NULL));
    for (int i = 0; i < MAX_TEST_LEN; ++i) {
      input_src[i] = 'A' + (rand() % HN_RANGE);
    }
    cout << ". done" << endl;
}

void generate_Sn()
{
    int cnt = 0;
    cout << "#generate_Hn ";
    vector < SType > res;
    size_t e_start = 0, e_end = 0, prev_e_end = 0;
    srand(time(NULL));
    //K개의 L(i)길이를 가지는 H(i) 세팅
    for (size_t i = 0; i < MAX_HN_SIZE; ++i) {
        //
        // if (cnt++ > PROCESS_TERM) {cout << "."; cnt%=PROCESS_TERM;}
        //
        e_end = AVG_HN_LEN * (i+1);
        e_start=rand()%(e_end-prev_e_end)+prev_e_end;
        size_t e_sz=rand()%(MAX_HN_LEN+1-MIN_HN_LEN)+MIN_HN_LEN;
        cout << "(" << i << ")s :" << e_start << ", e:" << e_end << " pre_e:" << prev_e_end << ", sz :" << e_sz << endl;
        //적합성
        if (e_start+e_sz-1 > e_end) {cout <<"#exeed"<<endl;i--;continue;}
        //할당
        char *u = new char[e_sz];
        copy(input_src+e_start, input_src+e_start+e_sz, u);//[start, end]
        SType ele(e_sz, u);
        delete u;
        cout << ele << endl;
        input_dst.push_back(ele);
        prev_e_end = e_end;
    }
    cout << " done" << endl;
}
vtype getPartialMatch(const SType& dst)
{
    uint m = dst.sz;
    vtype pi(m, 0);
    int begin = 1, matched = 0;
    while (begin + matched < m) {
        // if (cnt++ > PROCESS_TERM) {cout << "."; cnt%=PROCESS_TERM;}
        //matched
        if (dst.data[begin+matched] == dst.data[matched]) {
            matched++;
            pi[begin+matched-1]=matched;
        }
        //current characte is unmatched with source[i]
        else {
            //matched == 0 means "no jump for begin"
            if (matched == 0) {
                ++begin;
            } else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return pi;
}
vtype searchKMP(const char *_src, SType& _dst, vtype &_pi)
{
    //
    int cnt = 0;
    //
    vtype res;
    uint s = MAX_TEST_LEN, m = _dst.sz;
    int begin = 0, matched = 0;
    //
    while (begin <= s-m) {
        if (cnt++ > PROCESS_TERM) {cout << "."; cnt%=PROCESS_TERM;}
        //matched
        if (matched < m && _src[begin+matched] == _dst.data[matched]) {
            matched++;
            //satisfied all matched conditions
            if (matched == m) { res.push_back(begin);}
        }
        //current characte is unmatched with source[i]
        else {
            //matched == 0 means "no jump for begin"
            if (matched == 0) {
                ++begin;
            } else {
                begin += matched - _pi[matched-1];
                //adjustment for 'matched'
                matched = _pi[matched-1];
            }
        }
    }
    return res;
}
v_vtype find_KMP(const char *_src, vector < SType >& _dst)
{
    // v_ptype res;
    cout << "#find_KMP ";
    v_vtype res;
    v_vtype pi;
    //calculate Begin point
    for (int i = 0; i < _dst.size(); ++i) {
        cout << "\n1.dst\n" << _dst[i].data << endl;
        cout << "2.getPartialMatch" << endl;
        vtype pi = getPartialMatch(_dst[i]);
        print_vtype(pi);
        cout << " > calculate Begin point" << endl;
        vtype r = searchKMP(_src, _dst[i], pi);
        print_vtype(r);
        res.push_back(r);
    }
    cout << " done" << endl;
    return res;
}
v_vtype find_AHO(const short *_src, vector < SType >& dst)
{
    v_vtype res;
    return res;
}
void print_TESTCASE_N(const v_ptype& _res)
{
  ;
}
void print_vtype(const vtype &_src)
{
    for (size_t i=0; i < _src.size(); ++i) {
      cout <<
      // "(" << i << "):" <<
      _src[i];
    }
    cout << endl;
}
