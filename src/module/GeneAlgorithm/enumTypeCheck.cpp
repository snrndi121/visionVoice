#include <iostream>

using namespace std;
//
enum CType {
	c1 = '1',
	c2 = '2'
};
int main()
{
	char temp_c1 = '1', temp_c2 = '3';
	CType temp_C1 = c1;
	//check1
	cout << (temp_c1 == temp_C1) << endl;
	//check2
	cout << (temp_c2 == temp_C1) << endl;
	return 0;
}
