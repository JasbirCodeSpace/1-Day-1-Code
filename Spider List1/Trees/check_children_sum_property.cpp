#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node():left(NULL), right(NULL){};
    Node(int x):data(x), left(NULL), right(NULL){};
};

Node* insert(Node* root, int x){
    if(!root)
        return new Node(x);
    if(x <root->data)
            root->left = insert(root->left, x);
    else if(x > root->data)
            root->right = insert(root->right, x);
    return root; 
}

/*
    Time: O(N)
*/
bool checkSumProperty(Node* root){
    if(!root || (!root->left && !root->right))
        return true;
    int l = !root->left?0:root->left->data;
    int r = !root->right?0:root->right->data;
    return l+r==root->data&&checkSumProperty(root->left)&&checkSumProperty(root->right);
}
int main(int argc, char const *argv[])
{
    Node *root = new Node(10);
    root->left     = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->right = new Node(2);
    if(checkSumProperty(root))
        cout << "The given tree satisfies "
            << "the children sum property ";
    else
        cout << "The given tree does not satisfy "
            << "the children sum property ";
    cout<<endl;
    return 0;
}
