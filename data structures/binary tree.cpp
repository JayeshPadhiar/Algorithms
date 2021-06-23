#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node *left;
		Node *right;

		Node()
		{
			this->data = 0;
			this->left = NULL;
			this->right = NULL;
		}

		Node(int data)
		{
			this->data = data;
			this->left = NULL;
			this->right = NULL;
		}
};

int main()
{
	Node *root = new Node(1);

	root->left = new Node(2);
	root->right = new Node(3);

	return 0;
}