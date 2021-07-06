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

Node *push_front(Node **head, int num) // double pointer because head is not global
{
	Node *node = new Node(num);

	node->next = *head;
	*head = node;

	return node;
}

Node *push_back(Node **head, int num)
{
	Node *node = new Node(num);
	Node *temp = *head;

	if(temp == NULL)
	{
		*head = node;
		return *head;
	}

	while(temp->next)
	{
		temp = temp->next;
	}
	temp->next = node;

	return node;
}

Node *push_after(Node *node, int num, int data)
{
	while(node)
	{
		if(node->data == num)
		{
			Node *new_node = new Node(data);
			new_node->next = node->next;
			node->next = new_node;
			return new_node;
		}
		node = node->next;
	}
	cout<<"Number not found\n";
	return NULL;
}

Node *push_at(Node **head, int pos, int num)
{
	if(pos == 0)
	{
		Node *new_node = new Node(num);
		new_node->next = *head;
		*head = new_node;
		return *head;
	}

	if(*head == NULL)
	{
		Node *new_node = new Node(num);
		*head = new_node;
		return *head;
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

	return new_node;

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

int length_(Node *node) // find length recursively
{
	if(node)
		return length_(node->next) + 1;

	return 0;
}

int center(Node **head) // center using iteration
{
	int length = 0;
	Node *trav = *head;
	while(trav)
	{
		trav = trav->next;
		length++;
	}

	Node *node = *head;
	for(int i=0; i<(length/2); i++)
		node = node->next;

	return node->data;
}

int center_( Node *head) // center using two pointers
{
	Node *slow = head;
	Node *fast = head;

	while(fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	return slow->data;
}

void reverse(Node **head)
{
	Node *current = *head;
	Node *prev = NULL;
	Node *next;

	while(current != NULL)
	{
		next = current->next;
		current->next = prev;

		prev = current;
		current = next;
	}
	*head = prev;
}

void print_reverse(Node *head)  //prints reverse of linked list
{
	if(head != NULL)
	{
		print_reverse(head->next);
		cout<<head->data<<" ";
	}
}

Node *merge(Node **x, Node **y) // merges two sorted linked lists
{
	Node *a = *x;
	Node *b = *y;

	if(a == NULL && b == NULL)
		return NULL;

	Node *start = new Node();

	Node *headstart = start;

	while(a && b)
	{
		if((a->data) <= (b->data))
		{
			Node *nex = new Node(a->data);
			start->next = nex;
			a = a->next;
		}else{
			Node *nex = new Node(b->data);
			start->next = nex;
			b = b->next;
		}
		start = start->next;
	}

	while(a)
	{
		Node *nex = new Node(a->data);
		start->next = nex;
		start = start->next;
		a = a->next;
	}

	while(b)
	{
		Node *nex = new Node(b->data);
		start->next = nex;
		start = start->next;
		b = b->next;
	}

	delete_list(x);
	delete_list(y);

	return headstart->next;
}


int pop(Node **head)
{

	if(*head == NULL)
		return -1;

	if((*head)->next == NULL)
	{
		int data = (*head)->data;
		*head = NULL;
		return data;
	}

	Node *node = *head;
	while(node->next->next)
		node = node->next;

	Node *temp = node->next;
	int data = temp->data;

	node->next = NULL;

	delete temp;
	return data;
}


int main()
{
	Node *head = new Node(1);
	//push_back(&head, 5);
	//push_back(&head, 9);

	cout<<pop(&head);


	display(head);
}