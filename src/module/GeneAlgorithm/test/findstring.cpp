#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
	string src = "iam very fool man. are you agree? because I lost my lover";
	char dst;
	cout << ">> type src sentence : "; cin >> src;
	cout << ">> type dst character : "; cin >> dst; 
	vector < uint > found_index, wrong_index;
	for (uint i = 0; i < src.size(); ++i)
	{
		if (src[i] == dst) {
			cout << "found-";
			found_index.push_back(i);
		}
		else {
			cout << "wrong-";
			wrong_index.push_back(i);
		}
	}
	//found
	cout << "\n### found ### " << endl;
	for (uint i = 0; i < found_index.size(); ++i)
		cout << found_index[i] << "-";
	cout << endl;
	//wrong
	cout << "### wrong ### " << endl; 
	for (uint i = 0; i < wrong_index.size(); ++i)
		cout << wrong_index[i] << "-";
	return 0;

}
