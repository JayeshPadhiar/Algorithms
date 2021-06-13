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

void push_back(Node **head, int num)
{
	Node *node = new Node(num);
	Node *temp = *head;

	if(temp == NULL)
	{
		*head = node;
		return;
	}

	while(temp->next)
	{
		temp = temp->next;
	}
	temp->next = node;
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

void remove(Node **head, int num)
{
	Node *temp = *head;

	if(temp->data == num)
	{
		*head = temp->next;
		delete temp;
		return;
	}

	while(temp)
	{
		if(temp->next->data == num)
		{
			Node *del = temp->next;
			temp->next = temp->next->next;
			delete del;
			return;
		}
		temp = temp->next;
	}
}

void delete_list(Node **head)
{
	while(*head)
	{
		Node *node = *head;
		*head = (*head)->next;
		cout<<"Deleting "<<node->data<<endl;
		delete node;
	}
}

int main()
{
	Node *head = new Node(10);
	push_back(&head, 20);
	push_back(&head, 30);
	push_back(&head, 40);
	push_back(&head, 50);
	push_back(&head, 60);
	push_back(&head, 70);
	push_back(&head, 80);
	//remove(&head, 50);

	delete_list(&head);

	display(head);
}