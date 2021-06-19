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

class Queue {
	public:
		Node *front, *rear;

		Queue()
		{
			front = rear = NULL;
		}

		bool empty()
		{
			if(!(rear && front) && (front == rear))
				return true;

			return false;
		}

		void enq(int num)
		{
			if(rear == NULL)
			{
				Node *new_node = new Node(num);
				rear = front = new_node;
				return;
			}

			Node *new_node = new Node(num);
			rear->next = new_node;
			rear = rear->next;
		}

		int deq()
		{
			if(front == NULL)
			{
				cout<<"Empty Queue\n";
				return 0;
			}

			Node *temp = front;
			int data = temp->data;
			front = front->next;

			if(front == NULL)
				rear = NULL;

			delete temp;
			return data;
		}

		void display()
		{
			if(!front)
			{
				cout<<"Queue Empty\n";
				return;
			}

			Node *temp = front;
			while(temp)
			{
				cout<<temp->data<<" ";
				temp = temp->next;
			}
			cout<<endl;
		}
};


int main()
{
	Queue q;


	q.enq(1);
	cout<<q.front->data<< " "<<q.rear->data<<endl;

	q.enq(2);
	cout<<q.front->data<< " "<<q.rear->data<<endl;

	q.enq(3);
	cout<<q.front->data<< " "<<q.rear->data<<endl;

	q.enq(4);
	cout<<q.front->data<< " "<<q.rear->data<<endl;

	q.enq(5);
	cout<<q.front->data<< " "<<q.rear->data<<endl;

	q.deq();
	cout<<q.front->data<< " "<<q.rear->data<<endl;

	q.deq();
	cout<<q.front->data<< " "<<q.rear->data<<endl;
	q.deq();
	cout<<q.front->data<< " "<<q.rear->data<<endl;
	q.deq();
	cout<<q.front->data<< " "<<q.rear->data<<endl;

	q.deq();
	cout<<(q.front == q.rear)<<endl;




	return 0;
}