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

int pop(Node **head)
{
	if(*head == NULL)
	{
		cout<<"No element "<<endl;
		return -1;
	}

	if((*head)->next == NULL)
	{
		int data = (*head)->data;
		*head = NULL;
		return data;
	}

	Node *node = *head;
	while(node->next)
	{
		node = node->next;
	}
	int data = node->data;
	node->prev->next = NULL;
	delete node;
	return data;
}

int pop_front(Node **head)
{
	if(*head == NULL)
	{
		cout<<"No element"<<endl;
		return -1;
	}

	if((*head)->next == NULL)
	{
		int data = (*head)->data;
		*head = NULL;
		return data;
	}

	Node *temp = *head;
	int data = (*head)->data;

	(*head) = (*head)->next;
	delete temp;

	return data;
}

void remove(Node **head, int num)
{
	if(*head == NULL)
		return;


	Node *node = *head;
	while(node)
	{
		if(node->data == num)
		{
			if(node == *head)
			{
				cout<<"asdasd"<<endl;
				*head = (*head)->next;
				return;
			}

			if(node->prev != NULL)
			{
				node->prev->next = node->next;
			}

			if(node->next != NULL)
			{
				node->next->prev = node->prev;
			}

			delete node;
			return;
		}

		node = node->next;
	}
}

void reverse(Node **head)
{
	Node *prev = NULL;
	Node *curr = *head;

	while(curr)
	{
		curr->prev = curr->next;
		curr->next = prev;

		prev = curr;
		curr = curr->prev;
	}

	*head = prev;
}

int main()
{
	Node *head = NULL;
	push_back(&head, 2);
	push_back(&head, 3);
	push_back(&head, 4);

	reverse(&head);

	display(head);

	return 0;
}