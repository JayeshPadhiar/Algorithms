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

void push_front(Node **head, int num) // double pointer because head is not global
{
	Node *node = new Node(num);

	node->next = *head;
	*head = node;
}

void push_back(Node *head, int num)
{
	Node *node = new Node(num);

	while(head->next)
	{
		head = head->next;
	}
	head->next = node;
}

void push_after(Node *node, int num, int data)
{
	while(node)
	{
		if(node->data == num)
		{
			Node *new_node = new Node(data);
			new_node->next = node->next;
			node->next = new_node;
			return;
		}
		node = node->next;
	}
	cout<<"Number not found\n";
}


int main()
{
	Node *head = new Node(10);
	display(head);
}