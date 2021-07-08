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

void preorder(Node *node)
{
	if(node != NULL)
	{
		cout<<node->data<<" ";
		preorder(node->left);
		preorder(node->right);
	}
}

void inorder(Node *node)
{
	if(node != NULL)
	{
		inorder(node->left);
		cout<<node->data<<" ";
		inorder(node->right);
	}
}

void postorder(Node *node)
{
	if(node != NULL)
	{
		postorder(node->left);
		postorder(node->right);
		cout<<node->data<<" ";
	}
}

int main()
{
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	
	inorder(root);
	cout<<endl;
	
    preorder(root);
    cout<<endl;
    
    postorder(root);
    cout<<endl;

	return 0;
}
