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

Node *push(Node **head, int num)
{
	Node *node = new Node(num);

	node->next = *head;
	*head = node;

	return *head;
}


int main()
{
	Node *head = new Node(1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);
	push(&head, 6);
	push(&head, 7);

	return 0;
}