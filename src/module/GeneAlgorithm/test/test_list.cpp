#include <iostream>

using namespace std;

typedef struct Node {
	Node(){};
	Node(int n) { this->data = n, this->nextnode = nullptr;}
	int data;
	Node* nextnode = nullptr;
}Node;
typedef struct Node_list{
	int count = 0;
	Node* head = new Node();
	Node_list(){};
	void addNode(int _data) {
		Node* curNode = new Node(_data);
		if (count == 0) {
			head->nextnode = curNode; 
		}		
		else {
			Node* tempNode = head;
			while (tempNode->nextnode != nullptr) {	
				tempNode = tempNode->nextnode;
			}
			tempNode->nextnode = curNode;
		}
		count++;	
	};
	void print_data() 
	{
		Node* curNode = head;
		for (uint i = 0; i < count; ++i) {
			cout << curNode->data << '-';
			curNode = curNode->nextnode;
		}
	}
}Node_list;
int main()
{
	Node_list nl;
	nl.addNode(12);
	nl.addNode(13);
	nl.addNode(14);
	nl.print_data();
	return 0;
}
