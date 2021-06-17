#include <iostream>
using namespace std;

class Node
{
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

void display(Node *head)
{
	Node *node = head;

	do{
		cout<<node->data<<" ";
		node = node->next;
	}while(node != head);

}

void push(Node **head, int num)
{
	Node *new_node = new Node(num);

	if(*head == NULL)
	{
		*head = new_node;
		new_node->next = *head;
	}
	else
	{
		Node *temp = *head;

		while(temp->next != *head)
		{
			temp = temp->next;
		}
		new_node->next = *head;
		temp->next = new_node;
	}
}

int main()
{
	Node *head = new Node(1);
	head->next = head;

	//head = head->next;

	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);
	push(&head, 6);

	display(head);


	return 0;
}