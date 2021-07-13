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

// T(N) = O(N)
int countLeafNodes(Node* root){
    if(!root)
        return 0;
    if(!root->left && !root->right)
        return 1;
    return countLeafNodes(root->left)+countLeafNodes(root->right);
}

int main()
{


    Node *root = newNode(12);
    root->left = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(9);
    root->left->left->left = newNode(1);
    root->left->right->left = newNode(1);
	
    cout<<"Total leaf nodes: "<<countLeafNodes(root)<<endl;

	return 0;
}

