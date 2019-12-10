#include <iostream>

using namespace std;

struct atype
{
	int a = 2;
};
class mctype
{	
public:
	mctype(){};
	int a = 2;
};
typedef struct atype atype;

int main()
{
	atype* ptr_atype1;
	atype a1, b1;
	cout << "a addr :" << &a1 << ",b addr:" << &b1 << endl;
	b1 = a1;
	cout << "a addr:" << &a1 << ",b addr:" << &b1 << endl;
	//
	mctype c1, c2;
	cout << "c1 addr:" << &c1 << ",c2 addr :" << &c2 << endl;
	c1 = c2;
	cout << "c1 addr:" << &c1 << ",c2 addr :" << &c2 << endl;
	return 0;
}
