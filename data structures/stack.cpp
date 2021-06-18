#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node *next;

		Node()
		{
			this->data = 0;
			this->next = NULL;
		}

		Node(int data)
		{
			this->data = data;
			this->next = NULL;
		}
};


int main()
{
	Node *head = new Node(1);

	return 0;
}