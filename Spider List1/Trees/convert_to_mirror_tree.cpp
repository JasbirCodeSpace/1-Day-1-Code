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
void mirror1(Node* root){
    if(!root)
        return;
    mirror1(root->left);
    mirror1(root->right);
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

/*
    Time: O(N)
    Space: O(N)
*/
void mirror2(Node* root){
    if(!root)
        return;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        Node* temp = node->left;
        node->left = node->right;
        node->right = temp;
        if(node->left)
            q.push(node->left);
        if(node->right)
            q.push(node->right);
    }
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
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
     
    cout << "Inorder traversal of the constructed"
         << " tree is" << endl;
    inOrder(root);

    cout<<endl;

    mirror2(root);

    cout<<endl;

    cout << "\nInorder traversal of the mirror tree"
         << " is \n";
    inOrder(root);

    return 0;
}
