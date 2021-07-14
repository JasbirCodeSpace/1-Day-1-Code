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

int _checkSumTree(Node* root, bool& f){
    if(!root)
        return 0;
    if(!root->left && !root->right)
        return root->data;
    if(!f)
        return 0;
    int ls = _checkSumTree(root->left, f);
    int rs = _checkSumTree(root->right, f);
    if(ls+rs != root->data)
        f = false;
    return ls+rs+root->data;
}
// T(n) = O(n)
bool checkSumTree(Node* root){
    bool f = true;
    _checkSumTree(root, f);
    return f;
}
int main(int argc, char const *argv[])
{
    Node *root = newNode(26);
    root->left = newNode(10);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(6);
    root->right->right = newNode(3);
     
    if (checkSumTree(root))
        cout << "The given tree is a SumTree ";
    else
        cout << "The given tree is not a SumTree ";
    cout<<endl;
    return 0;
}
