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

void remove_at(Node **head, int pos)
{
	Node *node = *head;
	if(pos == 0 || (pos != 0 && !((*head)->next)))
	{
		*head = node->next;
		delete(node);
		return;
	}

	for(int i=1; i<pos; i++)
	{
		if(node->next->next)
			node = node->next;
	}

	Node *temp = node->next;
	node->next = node->next->next;
	delete temp;

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

int get(Node *head, int n)
{
	for(int i=0; i<n; i++)
	{
		if(head->next)
			head = head->next;
		else{
			return -1;
		}
	}
	return head->data;
}

int get_while(Node *head, int n) //same get using while loop
{
	int index = 0;

	while(head)
	{
		if(index == n)
		{
			return head->data;
		}
		head = head->next;
		index++;
	}

	return -1;
}

void swap_list(Node **a, Node **b)
{
	Node *temp = *a;
	*a = *b;
	*b = temp;
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
	Node *head = new Node(1);
	push_back(&head, 2);
    push_back(&head, 3);
    push_back(&head, 4);
    push_back(&head, 5);

    Node *hhhh = new Node(5);
	push_back(&hhhh, 6);
    push_back(&hhhh, 7);
    push_back(&hhhh, 8);
    push_back(&hhhh, 9);

    display(head);
    display(hhhh);

    swap_list(&head, &hhhh);

    display(head);
    display(hhhh);



}