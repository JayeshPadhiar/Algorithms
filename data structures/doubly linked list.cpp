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

Node *push_after(Node **head, int num, int data)
{
	Node *node = *head;

	while(node)
	{
		if(node->data == num)
		{
			Node *new_node = new Node(data);
			new_node->prev = node;
			new_node->next = node->next;

			if(node->next)
				node->next->prev = new_node;

			node->next = new_node;
			return new_node;
		}
		node = node->next;
	}
	return NULL;
}

int main()
{
	Node *head = new Node(1);
	push_back(&head, 2);
	push_back(&head, 3);
	push_back(&head, 4);
	Node *rev = push_back(&head, 5);

	Node *n = push_after(&head, 1, 50);

	display(head);
	display_reverse(rev);
	display_reverse(n);

	//display_reverse(r);


	return 0;
}