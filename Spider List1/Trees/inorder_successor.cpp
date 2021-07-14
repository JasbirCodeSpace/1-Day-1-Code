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
Node* minValue(Node* root){
    while(root->left){
            root = root->left;
    }
    return root;
}

// T(n) = O(h)
Node* inorderSuccessor(Node* root, Node* node){
    if(node->right)
        return minValue(node->right);
    Node* succ = NULL;
    while(root){
        if(root->data > node->data){
            succ = root;
            root = root->left;
        }
        else if(root->data < node->data)
            root = root->right;
        else
            break;
    }
    return succ;
}
int main(int argc, char const *argv[])
{
    Node *root = NULL, *temp, *succ, *min;
 
    // creating the tree given in the above diagram
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 22);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 14);
    temp = root->left->right->right;
     
    // Function Call
    succ = inorderSuccessor(root, temp);
    if (succ != NULL)
        printf(
            "\n Inorder Successor of %d is %d ",
            temp->data, succ->data);
    else
        printf("\n Inorder Successor doesn't exit");
    return 0;
}
