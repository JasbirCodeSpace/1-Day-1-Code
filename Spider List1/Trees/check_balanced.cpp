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

int _checkBalanced(Node* root, bool& f){
    if(!root)
        return 0;
    if(!f)
        return 0;
    int lh = _checkBalanced(root->left, f);
    int rh = _checkBalanced(root->right, f);
    if(abs(lh-rh)>1)
        f = false;
    return max(lh, rh)+1;
}
// T(n) = O(h)
bool checkBalanced(Node* root){

    bool f = true;
    _checkBalanced(root, f);
    return f;
}
int main(int argc, char const *argv[])
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(8);
 
    if (checkBalanced(root))
        cout << "Tree is balanced";
    else
        cout << "Tree is not balanced";
    cout<<endl;
    return 0;
}
