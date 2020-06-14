#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>


using namespace std;

const string in_trainlist_path="/media/uki408/Seagate Expansion Drive2/개인문서/기타/VOCmouth/PNGImages/img_list.txt";
const string in_tar_trainlist_path="/home/uki408/Documents/trainval.txt";
const string in_tar_testlist_path="/home/uki408/Documents/test.txt";
// const string out_trainlist_path="/media/uki408/Seagate Expansion Drive1/vocmouth/ImageSets/Main/trainval.txt";
// const string out_testlist_path="/media/uki408/Seagate Expansion Drive1/vocmouth/ImageSets/Main/test.txt";
const string out_trainlist_path="./trainval.txt";
const string out_testlist_path="./test.txt";

int input_file(vector <string>& tar, const string& path)
{
    ifstream ifs(path);
    if (ifs.fail()) {
        cerr << " > file is missing" << endl;
        throw -1;
    }
    string fn;
    while (ifs >> fn) {
        tar.push_back(fn);
    }
    ifs.close();
    cout << "# file :" << path << endl;
    cout << "# file size :" << tar.size() << endl;
    return 0;
}
bool cmpIdx (const string& a, const string& b) {
    stringstream sa, sb;
    int ia, ib;
    sa.str(a.substr(1, a.size() - 1));
    sb.str(b.substr(1, b.size() - 1));
    sa >> ia; sb >> ib;
    return ia < ib;
}
bool* chk;
int main()
{
    vector <string> originlist, trainlist, testlist;
    //init
    try {
      input_file(originlist, in_trainlist_path);
      sort(originlist.begin(), originlist.end(), cmpIdx);

      input_file(trainlist, in_tar_trainlist_path);
      sort(trainlist.begin(), trainlist.end(), cmpIdx);

      input_file(testlist, in_tar_testlist_path);
      sort(testlist.begin(), testlist.end(), cmpIdx);
    } catch (int err) {
        return err;
    }
    //last val
    string l1 = originlist.back();
    stringstream s1;
    s1.str(l1.substr(1, l1.size() - 1));
    int last_val;
    s1 >> last_val;
    chk = new bool[last_val+1];
    //
    for (int i = 0; i < last_val; ++i) { chk[i] = false;}
    int idx = 0;
    for (int i = 0; i < originlist.size(); ++i) {
        stringstream s2;
        s2.str(originlist[i].substr(1, originlist[i].size() - 1));
        s2 >> idx;
        chk[idx] = true;
    }
    //
    int cnt = 0;
    for (int i = 0; i <= last_val; ++i) { if (chk[i]) cnt++;}
    cout << "> val chk :" << cnt << endl;
    //

    //train val check
    ofstream ofs1(out_trainlist_path);
    cnt = 0;
    for (vector < string >::iterator it = trainlist.begin(); it != trainlist.end(); ++it) {
        stringstream s3;
        s3.str((*it).substr(1, (*it).size() - 1));
        s3 >> idx;
        if (chk[idx]) {
          ofs1 << *it << endl;
          chk[idx] = false;
        }
    }
    ofs1.close();
    //
    cnt = 0;
    for (int i = 0; i < last_val; ++i) { if (chk[i]) cnt++;}
    cout << "> val chk :" << cnt << endl;
    //
    //test val check
    ofstream ofs2(out_testlist_path);
    for (vector < string >::iterator it = testlist.begin(); it != testlist.end(); ++it) {
        stringstream s4;
        s4.str((*it).substr(1, (*it).size() - 1));
        s4 >> idx;
        if (chk[idx]) { ofs2 << *it << endl;}
    }
    ofs2.close();
    //write

    return 0;
}
