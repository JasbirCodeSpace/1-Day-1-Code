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

// T(n) = O(h)
int minValue(Node* root){

    Node* node = root;
    while(node->left){
        node = node->left;
    }
    return node->data;
}
int main(int argc, char const *argv[])
{
    Node* root = newNode(20);
    insert(root, 8);
    insert(root, 22);
    insert(root, 4);
    insert(root, 12);
    insert(root, 10);
    insert(root, 14);

    cout<<"Minimum value in given tree: "<<minValue(root)<<endl;
    return 0;
}
