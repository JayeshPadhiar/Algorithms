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
	cout<<endl;
}

void display_reverse(Node *tail)
{
	while(tail)
	{
		cout<<tail->data<<" ";
		tail = tail->prev;
	}
	cout<<endl;
}

Node *push_back(Node **head, int data)
{
	if(*head == NULL)
	{
		Node *new_node = new Node(data);
		*head = new_node;
		return *head;
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

Node *push_front(Node **head, int data)
{
	Node *node = new Node(data);

	if(*head)
	{
		cout<<"Done"<<endl;
		(*head)->prev = node;
		node->next = *head;
	}

	*head = node;
	return node;
}

int main()
{
	Node *head = NULL;
	//Node *n = push_front(&head, 2);
	//Node *o = push_front(&head, 3);
	push_back(&head, 5);

	display(head);
	//display(n);
	//display_reverse(o);
	display_reverse(head);

	return 0;
}