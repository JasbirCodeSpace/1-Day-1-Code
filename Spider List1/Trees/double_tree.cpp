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
void doubleTree(Node* root){
    if(!root)
        return;
    doubleTree(root->left);
    doubleTree(root->right);
    Node* temp = root->left;
    root->left = newNode(root->data);
    root->left->left = temp;
}

void printInorder(Node* root){
    if(!root)
    return;
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}
int main(int argc, char const *argv[])
{
    /* Constructed binary tree is
                  1
                /   \
               2     3
              / \
             4   5
    */
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
     
    cout << "Inorder traversal of the original tree is \n";
    printInorder(root);
    cout<<endl;
    doubleTree(root);
    cout << "\nInorder traversal of the double tree is \n";
    printInorder(root);
    cout<<endl;

    return 0;
}
