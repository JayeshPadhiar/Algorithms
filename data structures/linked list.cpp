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

void push_at(Node **head, int pos, int num)
{
	if(pos == 0)
	{
		cout<<"first";
		Node *new_node = new Node(num);
		new_node->next = *head;
		*head = new_node;
		return;
	}

	if(*head == NULL)
	{
		Node *new_node = new Node(num);
		*head = new_node;
		return;
	}

	Node *iter = *head;

	for(int i=0; i<pos-1; i++)
	{
		if(iter->next)
			iter = iter->next;
	}

	Node *new_node = new Node(num);

	new_node->next = iter->next;
	iter->next = new_node;

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
		delete node;
	}
}

int length(Node *head)
{
	int length = 0;

	while(head)
	{
		head = head->next;
		length++;
	}
	return length;
}

int main()
{
	Node *head = new Node(10);

	remove(&head, 10);

	push_front(&head, 100);

	cout<<length(head)<<endl;

	//delete_list(&head);

	display(head);
}