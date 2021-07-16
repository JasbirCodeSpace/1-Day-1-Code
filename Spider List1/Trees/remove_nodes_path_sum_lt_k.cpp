#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left, *right;
    Node():left(NULL), right(NULL){};
    Node(int x):data(x), left(NULL), right(NULL){};
};


void inorder(Node* root){
    if(!root)
        return;
    inorder(root->left);
    cout<<root->data<<' ';
    inorder(root->right);
}

/*
    Time: O(N)
*/
Node* removeNodes(Node* root, int sum){
    if(!root)
        return NULL;
    root->left = removeNodes(root->left, sum - root->data);
    root->right = removeNodes(root->right, sum - root->data);

    if(!root->left && !root->right){
        if(sum > root->data){
            delete root;
            return NULL;
        }
    }
    return root;
}
int main(int argc, char const *argv[])
{
    int k = 45;
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(12);
    root->right->right->left = new Node(10);
    root->right->right->left->right = new Node(11);
    root->left->left->right->left = new Node(13);
    root->left->left->right->right = new Node(14);
    root->left->left->right->right->left = new Node(15);
 
    cout <<"Tree before truncation\n";
    inorder(root);
    cout<<endl;
 
    root = removeNodes(root, k);
 
    cout <<"\n\nTree after truncation\n";
    inorder(root);
    cout<<endl;
    
    return 0;
}
