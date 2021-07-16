#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left, *right;
    Node():left(NULL), right(NULL){};
    Node(int x):data(x), left(NULL), right(NULL){};
};

// Time: O(N)
bool findAncestor(Node* root, int x){
    if(!root)
        return false;
    if(root->data == x)
        return true;
    if(findAncestor(root->left, x) || findAncestor(root->right, x)){
        cout<<"Ancestor of "<<x<<" is: "<<root->data<<endl;
        return true;
    }
    return false;
}
int main(int argc, char const *argv[])
{
        /* Construct the following binary tree
                  1
                /   \
               2     3
             /   \
            4     5
           /
          7
    */
    Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left  = new Node(7);
    
    findAncestor(root, 7);
    return 0;
}
