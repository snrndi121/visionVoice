#include <iostream>
#include <time.h>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

const string in_trainlist_path="/media/uki408/Seagate Expansion Drive1/Mouth/sharp/train.txt";
const string out_trainlist_path="/media/uki408/Seagate Expansion Drive1/vocmouth/ImageSets/Main/trainval.txt";
const string out_testlist_path="/media/uki408/Seagate Expansion Drive1/vocmouth/ImageSets/Main/test.txt";
int main()
{
    vector <string> trainlist, testlist;
    srand(time(NULL));
    ifstream ifs(in_trainlist_path);
    if (ifs.fail()) {
        cerr << " > file is missing" << endl;
        return -1;
    }
    string fn;
    while (ifs >> fn) {
        if (rand() % 10 < 8) {//80%
            trainlist.push_back(fn);
        } else { //20%
            testlist.push_back(fn);
        }
    }
    ifs.close();
    cout << " > train_size :" << trainlist.size() << endl;
    cout << " > test_size : " << testlist.size() << endl;
    //write
    ofstream ofs1(out_trainlist_path), ofs2(out_testlist_path);
    for (int i = 0; i < trainlist.size(); ++i) {ofs1 << trainlist[i] << endl;} ofs1.close();
    for (int i = 0; i < testlist.size(); ++i) {ofs2 << testlist[i] << endl;} ofs2.close();

    return 0;
}
