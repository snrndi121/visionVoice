vtype getPartialMatch(const FType* dst)
{
    uint m = dst->sz;
    vtype pi(m, 0);
    int begin = 1, matched = 0;
    while (begin + matched < m) {
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
vtype searchKMP(const char *_src, FType* _dst, vtype &_pi)
{
    //
    int cnt = 0;
    //
    vtype res;
    uint s = MAX_TEST_LEN, m = _dst->sz;
    int begin = 0, matched = 0;
    //
    while (begin <= s-m) {
        if (cnt++ > PROCESS_TERM) {cout << "."; cnt%=PROCESS_TERM;}
        //matched
        if (matched < m && _src[begin+matched] == _dst->data[matched]) {
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
v_vtype find_KMP(const char *_src, vector < FType* >& _dst)
{
    // v_ptype res;
    cout << "## Part3-1. Find_KMP ## ";
    v_vtype res;
    // v_vtype piArr;
    //calculate Begin point
    for (int i = 0; i < _dst.size(); ++i) {
        cout << "\n > dst : " << _dst[i]->data << endl;
        cout << " > getPartialMatch" << endl;
        vtype pi = getPartialMatch(_dst[i]);
        // piArr.push_back(pi);
        cout << " > calculate Begin point" << endl;
        vtype r = searchKMP(_src, _dst[i], pi);
        res.push_back(r);
    }
    cout << " done" << endl;
    return res;
}
/*
  * input_dst의 순차성 이용
*/
vtype searchKMP2(const char *_src, FType* _dst, size_t _prev, vtype &_pi)
{
    //
    int cnt = 0;
    //
    vtype res;
    uint s = MAX_TEST_LEN, m = _dst->sz;
    uint begin = _prev, matched = 0;
      //
    while (begin <= s-m) {
        if (cnt++ > PROCESS_TERM) {cout << "."; cnt%=PROCESS_TERM;}
        //matched
        if (matched < m && _src[begin+matched] == _dst->data[matched]) {
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
v_vtype find_KMP2(const char *_src, vector < FType* >& _dst)
{
    // v_ptype res;
    cout << "## Part3-1. Find_KMP ## ";
    v_vtype res;
    size_t prev_begin = 0;
    // v_vtype piArr;
    //부분 매치 문자열 세팅
    for (int i = 0; i < _dst.size(); ++i) {
        cout << "\n > dst : " << _dst[i]->data;
        cout << "\n > getPartialMatch" << endl;
        vtype pi = getPartialMatch(_dst[i]);
        for(int i = 0; i < pi.size(); ++i){ cout << pi[i];}
        cout << "\n > calculate Begin point" << endl;
        vtype r = searchKMP2(_src, _dst[i], prev_begin, pi);
        cout << r[0] << endl;
        //순차성 적용
        if (r.size() == 1) {prev_begin = r[0];}
        res.push_back(r);
    }
    cout << " done" << endl;
    return res;
}
