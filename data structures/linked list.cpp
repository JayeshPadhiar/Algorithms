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

void display(Node *node)
{
	while(node)
	{
		cout<<node->data<<" ";
		node = node->next;
	}

	cout<<endl;
}

int search(Node *node, int num)
{
	int index = 0;
	while(node)
	{
		if(node->data == num)
			return index;

		node = node->next;
		index++;
	}
	return -1;
}

int main()
{
	Node *head = new Node(10);
	display(head);
}