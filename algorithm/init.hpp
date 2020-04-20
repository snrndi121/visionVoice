#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

#include "userType.hpp"


//def
typedef pair < int, int > ptype;
typedef vector < int > vtype;
typedef vector < ptype > v_ptype;
typedef vector < vtype > v_vtype;

#define MAX_TEST_LEN 1000
#define HN_RANGE 16
#define MIN_HN_LEN 10
#define MAX_HN_LEN 20
#define MAX_HN_SIZE 1
#define AVG_HN_LEN MAX_TEST_LEN/MAX_HN_SIZE
#define PROCESS_TERM 5000

//universe variable
char* input_src;
vector < FType *> input_dst;
v_ptype res1, res2;

/*
  * Generation Sample
*/
//var
void generate_TESTCASE_N()
{
    cout << "## Part1. generate_TESTCASE_N .. ## ";
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
    cout << "## Part2. generate_Hn .. ## ";
    vector < FType > res;
    size_t e_start = 0, e_end = 0, prev_e_end = 0, e_sz;
    char *buffer = new char[MAX_HN_LEN];
    srand(time(NULL));
    vector <FType*> sample;
    //K개의 L(i)길이를 가지는 H(i) 세팅
    for (size_t i = 0; i < MAX_HN_SIZE; ++i) {
        e_end = AVG_HN_LEN * (i+1);
        e_start=rand()%(e_end-prev_e_end)+prev_e_end;
        e_sz=rand()%(MAX_HN_LEN+1-MIN_HN_LEN)+MIN_HN_LEN;
        cout << "\n(" << i << ")s :" << e_start << ", e:" << e_end << " pre_e:" << prev_e_end << ", sz :" << e_sz << endl;
        //적합성
        if (e_start+e_sz-1 > e_end) {i--; continue;}
        //할당
        copy(input_src+e_start, input_src+e_start+e_sz, buffer);//[start, end]
        FType* ele = new FType(e_sz, buffer);
        input_dst.push_back(ele);
        prev_e_end = e_end;
    }
    cout << " done" << endl;
}
