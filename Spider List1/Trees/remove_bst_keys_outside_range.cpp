#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left, *right;
    Node():left(NULL), right(NULL){};
    Node(int x):data(x), left(NULL), right(NULL){};
};

Node* insert(Node* root, int x){
    if(!root)
        return new Node(x);
    if(x < root->data)
        root->left = insert(root->left, x);
    else if(x > root->data)
        root->right = insert(root->right, x);
    return root;
}

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
Node* removeNodes(Node* root, int min, int max){
    if(!root)
        return NULL;
    root->left = removeNodes(root->left, min, max);
    root->right = removeNodes(root->right, min, max);
    if(root->data < min ){
        Node* rchild = root->right;
        delete root;
        return rchild;
    }
    if(root->data > max){
        Node* lchild = root->left;
        delete root;
        return lchild;
    }
    return root;
}
int main(int argc, char const *argv[])
{
    Node* root = NULL;
    root = insert(root, 6);
    root = insert(root, -13);
    root = insert(root, 14);
    root = insert(root, -8);
    root = insert(root, 15);
    root = insert(root, 13);
    root = insert(root, 7);
 
    cout << "Inorder traversal of the given tree is: ";
    inorder(root);
    cout<<endl;
 
    root = removeNodes(root, -10, 13);
 
    cout << "\nInorder traversal of the modified tree is: ";
    inorder(root);
    cout<<endl;
    
    return 0;
}
