#include<bits/stdc++.h>
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

void printLeaves(Node* root){
    if(!root)
        return;
    printLeaves(root->left);
    if(!root->left && !root->right){
        cout<<root->data<<" ";
    }
    printLeaves(root->right);
}

void printLeftBoundary(Node* root){
    if(!root)
        return;
    
    if(root->left){
        cout<<root->data<<' ';
        printLeftBoundary(root->left);
    }
    else if(root->right){
        cout<<root->data<<" ";
        printLeftBoundary(root->right);
    }
}

void printRightBoundary(Node* root){
    if(!root)
        return;
    if(root->right){
        printRightBoundary(root->right);
        cout<<root->data<<" ";
    }
    else if(root->left){
        printRightBoundary(root->left);
        cout<<root->data<<' ';
    }

}

// T(n) = O(n)
void boundaryTraversal(Node* root){
    if(!root)
        return;
    cout<<root->data<<" ";
    printLeftBoundary(root->left);
    printLeaves(root->left);
    printLeaves(root->right);
    printRightBoundary(root->right);
    cout<<endl;
}
int main(int argc, char const *argv[])
{
    Node* root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);
    boundaryTraversal(root);
    return 0;
}
