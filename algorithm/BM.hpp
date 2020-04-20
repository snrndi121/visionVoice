// vtype boyer_moore(const char* _src, FType* _dst) {
//     int s_size = MAX_TEST_LEN;
//     int d_size = _dst->sz;
//     vtype result;
//     int begin = d_size - 1, dst_last;
//     int matched = 0;
//     while (begin < s_size) {
//         dst_last = d_size - 1;
//         // case1.문자열 끝이 같은 경우
//         int src_last = begin;
//         if (_src[src_last] == _dst->data[dst_last]) {
//             //끝에서부터 순차적으로 탐색함
//             while (_src[src_last] == _dst->data[dst_last]) {
//                 src_last--;
//                 dst_last--;
//                 if (dst_last == -1) break;
//             }
//             // 모든 패턴 일치
//             if (dst_last == -1) {
//                 result.push_back(src_last + 1);
//                 begin += d_size;
//             }
//             // 패턴 불일치
//             else {
//                 begin += d_size;
//             }
//         }
//         // case2.문자열 끝이 다른 경우
//         else {
//             // 끝 문자가 패턴 내에 존재하는지 검사
//             bool exist = false;
//             int k;
//             for (k = 0; k < d_size - 1; k++) {
//                 if (_src[src_last] == _dst->data[k]) {
//                     exist = true;
//                     break;
//                 }
//             }
//             // 존재하는 경우
//             if (exist) {
//                 begin += d_size - k - 1;
//             }
//             // 존재하지 않는 경우
//             else {
//                 begin += d_size;
//             }
//         }
//     }
//     return result;
// }
vtype boyer_moore(const char* _src, FType* _dst) {
    int s_size = MAX_TEST_LEN;
    int d_size = _dst->sz;
    vtype result;
    int begin = d_size - 1, dst_last;
    int matched = 0;
    cout << _src << endl;
    cout << "s_sz :" << s_size << ", d_sz:" << d_size << endl;
    while (begin < s_size) {
        dst_last = d_size - 1;
        // case1.문자열 끝이 같은 경우
        int src_last = begin;
        cout << "begin :" << begin << endl;
        cout << "(" << _src[src_last] << ", " <<  _dst->data[dst_last] << ")" << endl;
        if (_src[src_last] == _dst->data[dst_last]) {
            cout << " > last is same" << endl;
            //끝에서부터 순차적으로 탐색함
            while (_src[src_last-matched] == _dst->data[dst_last-matched]) {
                src_last--;
                dst_last--;
                matched++;
                if (matched == d_size) break;
            }
            // 모든 패턴 일치
            if (matched == d_size) {
                cout << "  >> all same" << endl;
                result.push_back(src_last + 1);
                begin += d_size;
            }
            // 패턴 불일치
            else {
                cout << "  >> not all same" << endl;
                begin += d_size;
            }
            matched = 0;
        }
        // case2.문자열 끝이 다른 경우
        else {
            cout << " > last different" << endl;
            // 끝 문자가 패턴 내에 존재하는지 검사
            bool exist = false;
            int k;
            for (k = 0; k < d_size - 1; k++) {
                if (_src[src_last] == _dst->data[k]) {
                    exist = true;
                    break;
                }
            }
            // 존재하는 경우
            cout << " > find the character in Pattern" << endl;
            if (exist) {
                cout << "  >> find" << endl;
                begin += d_size - k - 1;
            }
            // 존재하지 않는 경우
            else {
                cout << "  >> not find" << endl;
                begin += d_size;
            }
        }
    }
    return result;
}
v_vtype find_BM(const char* _src, vector < FType* >& _dst)
{
    cout << "## Part3-2. Find_Boyer-Moore ## ";
    v_vtype res;
    size_t prev_begin = 0;
    for (int i = 0; i < _dst.size(); ++i) {
        cout << "\n > dst : " << _dst[i]->data;
        cout << "\n > calculate Begin point" << endl;
        vtype r = boyer_moore(_src, _dst[i]);
        cout << r.size() << endl;
        //순차성 적용
        res.push_back(r);
    }
    cout << " done" << endl;
    return res;
}
