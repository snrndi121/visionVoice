#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

#define PERCENT_OF_TEST 10

const string NAME_DATA_FILE = "./data_list.md";
const string NAME_TRAIN_FILE = "./trainval.md";
const string NAME_TEST_FILE = "./test.md";

vector < string > data_all;
vector < bool > randDupChecker;
void init();//변수 초기 세팅(set initial variables' settings)
void read_data_list();//데이터 읽기 (read data set)
void splitData2Test();//테스트 데이터 쪼개기 (Split data_list to test)
void splitData2Train();//훈련 데이터 쪼개기 (Split data_list to train)
int main()
{
    read_data_list();
    init();
    splitData2Test();
    splitData2Train();
    return 0;
}
void init()
{
    for (uint i = 0; i < data_all.size(); ++i) {
        randDupChecker.push_back(false);
    }
}
void read_data_list()
{
    ifstream ifs("data_list.md");
    if (ifs.fail()) {
        cout << " >> no such " << NAME_DATA_FILE << " file in this directory" << endl;
        return ;
    }
    string s;
    while (ifs >> s) {
        data_all.push_back(s);
    }
    ifs.close();
    cout << "\n ### Data_set Size : " << data_all.size() << endl;
}
void splitData2Test()
{
    cout << "\n ### Set test_data_list ### " << endl;
    uint numOftest = data_all.size() * PERCENT_OF_TEST / 100;
    cout << " >> The number of test is " << numOftest << endl;

    srand((unsigned int) time(NULL));
    vector < string > data_test;
    for (uint i = 0; i < numOftest; ++i) {
          uint target = rand() % data_all.size();
          //중복되지 않았다면 (if target is not duplicated)
          if (!randDupChecker[target]) {
              data_test.push_back(data_all[target]);
              randDupChecker[target] = true;
          }
    }
    //save test file
    ofstream ofs(NAME_TEST_FILE);
    for (uint i = 0; i < data_test.size(); ++i) {
        ofs << data_test[i] << endl;
    }
    ofs.close();
}
void splitData2Train()
{
    cout << "\n ### Set train_data_list ### " << endl;
    vector < string > data_train;
    for (uint i = 0; i < data_all.size(); ++i) {
        if (!randDupChecker[i]) {
            data_train.push_back(data_all[i]);
        }
    }
    //save train file
    ofstream ofs(NAME_TRAIN_FILE);
    for (uint i = 0; i < data_train.size(); ++i) {
        ofs << data_train[i] << endl;
    }
    ofs.close();
}
