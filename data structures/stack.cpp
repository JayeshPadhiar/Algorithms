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

bool isempty(Node *head)
{
	if(head)
		return false;

	return true;
}

void display(Node *head)
{
	if(!head)
	{
		cout<<"Stack Empty\n";
		return;
	}

	while(head)
	{
		cout<<head->data<<endl;
		head = head->next;
	}
}

int pop(Node **head)
{
	if((*head) == NULL)
	{
		cout<<"Stack Empty\n";
		return 0;
	}

	int data = (*head)->data;
	Node *temp = *head;

	*head = (*head)->next;
	delete temp;

	return data;
}

int peek(Node *head)
{
	if(head == NULL)
	{
		cout<<"Stack Empty\n";
		return 0;
	}

	return head->data;
}

int size(Node *head)
{
	int size = 0;
	while(head)
	{
		size++;
		head = head->next;
	}

	return size;
}

int main()
{
	Node *head = new Node(1);
	push(&head, 2);
	push(&head, 3);

	cout<<size(head)<<endl;

	return 0;
}