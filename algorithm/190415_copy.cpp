/*
  * 날짜 : 190415
  * 내용 : 긴 문자열에서 특정 문자열 찾기 (KMP, 아호코라식)
  * 특이사항
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
#define MIN_HN_LEN 30
#define MAX_HN_LEN 50
#define MAX_HN_SIZE 10
#define AVG_HN_LEN MAX_TEST_LEN/MAX_HN_SIZE
#define PROCESS_TERM 5
//def
template <typename T>
struct HnType {
  HnType(short _sz, T *_data) : sz(_sz), data(_data){
      data = new T[_sz];
      for (short i = 0; i < _sz; ++i) { data[i]=_data[i];}
  }
  friend ostream&
  operator<<(ostream& ost, const HnType<T>& s) {
      for (short i = 0; i < s.sz; ++i) { ost << s.data[i];}
      return ost;
  }
  //var
  uint sz = 0;
  T *data;
};
typedef pair < int, int > ptype;
typedef vector < int > vtype;
typedef vector < ptype > v_ptype;
typedef vector < vtype > v_vtype;
//var
v_ptype res1, res2;
//func
short* generate_TESTCASE_N();
vector < HnType <short>* > generate_Hn(const short *);
v_vtype find_KMP(const short*, vector < HnType<short>* >&);
v_vtype find_AHO(const short*, vector < HnType<short>* >&);
void print_TESTCASE_N(const v_ptype&);
int main()
{
    short *src = generate_TESTCASE_N();
    vector < HnType<short>* > dst = generate_Hn(src);
    find_KMP(src, dst);
    // res2 = find_AHO(src, dst);
    //
    print_TESTCASE_N(res2);
    // print_TESTCASE_N(res1);
    return 0;
}
short* generate_TESTCASE_N()
{
    cout << "#generate_TESTCASE_N ..";
    short *input = new short[MAX_TEST_LEN];
    srand(time(NULL));
    for (int i = 0; i < MAX_TEST_LEN; ++i) {
      input[i] = (rand() % 10);
    }
    cout << ". done" << endl;
    return input;
}
vector < HnType <short>* > generate_Hn(const short *_src)
{
    int cnt = 0;
    cout << "#generate_Hn ";
    vector < HnType <short>* > res;
    short e_start = 0, e_end = 0, prev_e_end = 0;
    srand(time(NULL));
    //K개의 L(i)길이를 가지는 H(i) 세팅
    for (int i = 0; i < MAX_HN_SIZE; ++i) {
        //
        if (cnt++ > PROCESS_TERM) {cout << "."; cnt%=PROCESS_TERM;}
        //
        e_end = AVG_HN_LEN * (i+1);
        e_start=rand()%(e_end-prev_e_end)+prev_e_end;
        short e_sz=rand()%(MAX_HN_LEN+1-MIN_HN_LEN)+MIN_HN_LEN;
        // cout << "(" << i << ")s :" << e_start << ", e:" << e_end << " pre_e:" << prev_e_end << ", sz :" << e_sz << endl;
        //적합성
        if (e_start+e_sz-1 > e_end) {i--;continue;}
        //할당
        short *u = new short[e_sz];
        copy(_src+e_start, _src+e_end-1, u);
        HnType<short> ele(e_sz, u);
        // cout << ele << endl;
        res.push_back(&ele);
        prev_e_end = e_end;
    }
    cout << " done" << endl;
    return res;
}
vtype getPartialMatch(const HnType<short>* dst)
{
    cout << " > searchKMP ";
    uint m = dst->sz;
    vtype pi(m, 0);
    int begin = 1, matched = 0;
    while (begin + matched < m) {
        // if (cnt++ > PROCESS_TERM) {cout << "."; cnt%=PROCESS_TERM;}
        //matched
        if (dst->data[begin+matched] == dst->data[matched]) {
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
vtype searchKMP(const short *_src, HnType<short>* dst)
{
    //
    cout << " > searchKMP ";
    int cnt = 0;
    //
    uint s = MAX_TEST_LEN, m = dst->sz;
    vtype res;
    vtype pi = getPartialMatch(dst);
    int begin = 0, matched = 0;
    while (begin <= s-m) {
        if (cnt++ > PROCESS_TERM) {cout << "."; cnt%=PROCESS_TERM;}
        //matched
        if (matched < m && _src[begin+matched] == dst->data[matched]) {
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
                begin += matched - pi[matched-1];
                //adjustment for 'matched'
                matched = pi[matched-1];
            }
        }
    }
    return res;
}
v_vtype find_KMP(const short *_src, vector < HnType<short>* >& dst)
{
    // v_ptype res;
    int cnt = 0;
    cout << "#find_KMP ";
    v_vtype res;
    for (int i = 0; i < dst.size(); ++i) {
        cout << "\n(" << i << "):";
        vtype r = searchKMP(_src, dst[i]);
        res.push_back(r);
    }
    cout << " done" << endl;
    return res;
}
v_vtype find_AHO(const short *_src, vector < HnType<short>* >& dst)
{
    v_vtype res;
    return res;
}
void print_TESTCASE_N(const v_ptype& _res)
{
  ;
}
