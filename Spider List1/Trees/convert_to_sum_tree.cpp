#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node():left(NULL), right(NULL){};
    Node(int x):data(x),left(NULL), right(NULL){}; 
};

/*
    Time: O(N)
    Space: O(h)
*/
int sumTree(Node* root){
    if(!root)
        return 0;
    int ls = sumTree(root->left);
    int rs = sumTree(root->right);
    int x = root->data;
    root->data = ls+rs;
    return x+ls+rs;
}
void inOrder(Node* root){
    if(!root)
        return;
    inOrder(root->left);
    cout<<root->data<<' ';
    inOrder(root->right);
}
int main(int argc, char const *argv[])
{
    Node *root = NULL;
     
    root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(6);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    root->right->left = new Node(7);
    root->right->right = new Node(5);
     
    sumTree(root);

    cout<<"Inorder Traversal of the resultant tree is: \n";
    inOrder(root);
    cout<<endl;
    return 0;
}
