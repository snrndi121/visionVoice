#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
		int src[] = {-1,2,3,4,-1,-1,-100,-1,-1,10};
		int dst[3], dst2[3];
		fill_n(dst, 3, -100);
		fill_n(dst2, 3, -100);

		copy(src+1, src+1+3, dst);
		for (size_t i = 0; i < 3; ++i) {
			cout << dst[i] << endl;
		}
		cout << "\n#\n";// << endl;
		copy(src+3, src+3+3, dst2);
		for (size_t i = 0; i < 5; ++i) {
			cout << dst2[i] << endl;
		}
		// cout << "test2" << endl;
		// for (int i = 0; i<10;++i) {
		// 		int u = rand()%(10-1+1) + 1;//0~9 -> 1~10
		// 		cout << u << endl;
		// }
		return 0;

}
