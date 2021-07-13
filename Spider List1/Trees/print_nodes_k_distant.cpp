#include<bits/stdc++.h>
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
void printKdistant(Node* root, int k){
    if(!root || k<0)
        return;
    if(k == 0){
        cout<<root->data<<" ";
    }
    printKdistant(root->left, k-1);
    printKdistant(root->right, k-1);
}
int main()
{


  /* Constructed binary tree is
              1
            /   \
           2     3
          / \    /
         4   5  8
    */
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(8);
    printKdistant(root, 2);
    cout<<endl;
	return 0;
}

