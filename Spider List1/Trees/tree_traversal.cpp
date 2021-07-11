#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
};

Node* newNode(int x){
    Node* node = new Node();
    node->data = x;
    node->left = node->right = NULL;
    return node;
}

void preOrder(Node* root){
    if(root == NULL)
        return;
    cout<<root->data<<' ';
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root){
    if(root == NULL)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(Node* root){
    if(root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
int main(int argc, char const *argv[])
{

    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    cout << "\nPreorder traversal of binary tree is \n";
    preOrder(root);
 
    cout << "\nInorder traversal of binary tree is \n";
    inOrder(root);
 
    cout << "\nPostorder traversal of binary tree is \n";
    postOrder(root);
    return 0;
}
