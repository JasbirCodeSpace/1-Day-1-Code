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
// T(n) = O(min(m, n))
bool checkIdentical(Node* root1, Node* root2){
    if(root1== NULL && root2==NULL)
        return true;
    else if(root1 && root2){
        return root1->data == root2->data && checkIdentical(root1->left, root2->left) && checkIdentical(root1->right, root2->right);
    }
    return false;
}
int main(int argc, char const *argv[])
{

    Node *root1 = newNode(1);
    Node *root2 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
 
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);
 
    if(checkIdentical(root1, root2))
        cout << "Both tree are identical.";
    else
        cout << "Trees are not identical.";
    return 0;
}
