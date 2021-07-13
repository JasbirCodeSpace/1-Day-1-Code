#include<iostream>
using namespace std;

class Node
{   public:
	int data;
	Node *left, *right;
};

Node* newNode(int data)
{
	Node *temp = new Node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// T(n) = O(n)
void deleteTree(Node* root){
    if(root==NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
int main()
{


    Node *root = newNode(12);
    root->left = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(9);
    root->left->left->left = newNode(1);
    root->left->right->left = newNode(1);
	
    deleteTree(root);
    root = NULL;
    cout<<"Tree deleted"<<endl;

	return 0;
}

