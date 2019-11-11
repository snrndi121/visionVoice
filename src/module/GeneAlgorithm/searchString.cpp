#include <iostream>
#include <vector>

using namespace std;

//문자열 내 문자 검색용
int main()
{
    string str = "1234243395743832984328942";
    vector < string > in_str;

    int i = 0;
    while (i++ < 3) {
        string s;
        cin >> s;
        in_str.push_back(s);
    }
    vector < pair < string, vector < uint > > >res;
    for (uint i = 0; i < in_str.size(); ++i) {
        size_t j = str.find(in_str[i]);
        vector < uint > z;
        while (j != string::npos) {
            // if (j != string::npos)
              z.push_back(j);
              j = str.find(in_str[i], j + 1);
        }
        res.push_back(make_pair(in_str[i], z));
        z.clear();
    }
    //print
    for (uint i = 0; i != res.size(); ++i) {
        cout << res[i].first << " :";
        for (uint j = 0; j != res[i].second.size(); ++j)
          cout << res[i].second[j] << ", ";
        cout << endl;
    }
    return 0;
}
