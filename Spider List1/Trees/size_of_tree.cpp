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

int size(Node* root){
    if(root == NULL)
        return 0;
    return size(root->left) + 1 + size(root->right);
}
int main(int argc, char const *argv[])
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout<<"Size of given tree: "<<size(root)<<endl;
    return 0;
}
