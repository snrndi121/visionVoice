#include <iostream>

using namespace std;

class btype {
	int b;
};
class atype {
public :
	atype(){};
	int getType () const { return a;}
	//btype getClass () const { cout << "1" << endl;return b;}
	btype& getClass () { cout << "2" << endl;return b;}
	int a = 1;
	btype b;
};

int main()
{
	atype a1;
	cout << "addr_atype_b : " << &a1.b << endl;
	btype& b1 = a1.getClass();
	btype* ptr_b1 = &a1.getClass();
	cout << "addr_ptr_btype :" << ptr_b1 << endl;
	cout << "addr_ref_btype :" << &b1 << endl;	
	return 0;
}
	
