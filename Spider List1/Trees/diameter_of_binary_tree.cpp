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

int height(Node* root, int& d){
    if(root == NULL)
        return 0;
    int lh = height(root->left, d);
    int rh = height(root->right, d);
    d = max(d, lh+rh+1);
    return max(lh, rh)+1;
}

// Time complexity: O(N)
int diameter(Node* root){
    if(root==NULL)
        return 0;
    int d = -1;
    height(root, d);
    return d;
}
int main(int argc, char const *argv[])
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    cout << "Diameter of the given binary tree is " << diameter(root)<<endl;
    return 0;
}
