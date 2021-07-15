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
    Time: O(n)
    Space: O(h)
*/
void addGreaterUtil(Node* root, int& sum){
    if(!root)
        return;
    addGreaterUtil(root->right, sum);
    sum += root->data;
    root->data = sum;
    addGreaterUtil(root->left, sum);
}
void addGreater(Node* root){
    int sum = 0;
    addGreaterUtil(root, sum);
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
    /* Create following BST
                  5
                /   \
               2     13 
    */
    Node *root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(13);
 
    cout << "Inorder traversal of the "
         << "given tree" << endl;
    inOrder(root);
 
    addGreater(root);
    cout << endl;
    cout << "Inorder traversal of the "
         << "modified tree" << endl;
    inOrder(root);
    cout<<endl;
    return 0;
}
