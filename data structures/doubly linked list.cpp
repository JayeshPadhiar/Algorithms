#include <iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *next;
		Node *prev;

		Node()
		{
			this->data = 0;
			this->next = NULL;
			this->prev =  NULL;
		}

		Node(int data)
		{
			this->data = data;
			this->next = NULL;
			this->prev = NULL;
		}
};

void display(Node *head)
{
	while(head)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
}

Node *push_back(Node **head, int data)
{
	if(*head == NULL)
	{
		Node *new_node = new Node(data);
		*head = new_node;
	}

	Node *node = *head;

	while(node->next)
	{
		node = node->next;
	}

	Node *new_node = new Node(data);
	new_node->prev = node;
	node->next = new_node;

	return new_node;
}

int main()
{
	Node *head = new Node(1);
	push_back(&head, 2);
	push_back(&head, 3);
	push_back(&head, 4);
	Node *x = push_back(&head, 5);

	return 0;
}