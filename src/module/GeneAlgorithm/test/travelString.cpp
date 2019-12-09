#include <iostream>

using namespace std;

int main()
{
    string s = "1234";
    for (uint i = 0; i < s.size(); ++i) {
        cout << s[i] << endl;
    }
    size_t i = s.find(s[0]);
    cout << s[i] << endl;
    return 0;
}
