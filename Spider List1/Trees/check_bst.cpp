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

Node* insert(Node* root, int x){
    if(!root)
        return newNode(x);
    else{
        if(x <= root->data)
            root->left = insert(root->left, x);
        else if(x>root->data)
            root->right = insert(root->right, x);
        return root;
    }
}


// T(n) = O(n)
bool checkBST(Node* root, Node* l = NULL, Node* r = NULL){

    if(!root)
        return true;
    if(l && root->data <= l->data)
        return false;
    if(r && root->data >= r->data)
        return false;
    return checkBST(root->left, l, root)&&checkBST(root->right, root, r);
}
int main(int argc, char const *argv[])
{
    Node *root = newNode(26);
    root->left = newNode(10);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(6);
    root->right->right = newNode(3);
     
    if (checkBST(root))
        cout << "The given tree is a BST ";
    else
        cout << "The given tree is not a BST ";
    cout<<endl;
    return 0;
}
