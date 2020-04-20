/**
  * 업데이트 날짜 : 190416
  * 내용 : 긴 문자열에서 특정 문자열 찾기 (KMP, 아호코라식)
  * 특이사항

    1. 특정 문자열(S[i]) 간의 순차성
      - S[i+1]는 S[i]보다 나중에 생성된 값
    1-1. 1번 내용을 사용하려면,
      - 저 begin이 틀림없어야함. 나중에 추후 특이사항을 받고도 의심하지 않을 수 있나?
      - 대전제는, 추후 특이사항을 보장한다면 이용가능함.
      - 그 경우는 KMP2로 따로 구현.

  * 추후 특이사항
    1. 완벽히 일치하지 않는 타겟
      (1) 길이 일치
        - 내용이 다른 경우,

      (2) 내용 일치
        - 중간에 필요없는 문자(열)이 삽입된 경우,
*/
#include "init.hpp"
#include "KMP.hpp"
#include "BM.hpp"
//func
void generate_TESTCASE_N();
void generate_Sn();
v_vtype find_KMP(const char*, vector < FType* >&);
v_vtype find_KMP2(const char*, vector < FType* >&);//입력값의 순차성 특성 적용
v_vtype find_BM(const char*, vector < FType* >&);
v_vtype find_AHO(const char*, vector < FType* >&);
void print_TESTCASE_N(const v_ptype&);
void print_vtype(const vtype &);
int main()
{
    generate_TESTCASE_N();
    generate_Sn();
    /*
      * KMP
    */
    // find_KMP(input_src, input_dst);
    // end = clock();
    // cout << (float)(end-start)/10000 << endl;
    // //
    clock_t start = clock(), end;
    // start = clock();
    // find_KMP2(input_src, input_dst);
    // end = clock();
    // cout << (float)(end-start)/10000 << endl;
    /*
      * Boyer-Moore
    */
    start = clock();
    find_BM(input_src, input_dst);
    end = clock();
    cout << (float)(end-start)/10000 << endl;
    /*
      * AHO
    */
    // // res2 = find_AHO(src, dst);
    //
    // print_TESTCASE_N(res2);
    // print_TESTCASE_N(res1);
    return 0;
}

v_vtype find_AHO(const short *_src, vector < FType* >& dst)
{
    v_vtype res;
    return res;
}
