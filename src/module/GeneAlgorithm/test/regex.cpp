#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main()
{
    string full_digit = "ffjksdhkfhekfhsekufhuse;kfhukwkbfskfbek";
    smatch m;
    regex e ("([^fj$])");
    //
    cout << ">> serach result \n";
    while (regex_search(full_digit, m, e)) {
        for (auto x:m) cout << x << " ";
        cout << endl;
        full_digit = m.suffix().str();
    }

    return 0;
}
