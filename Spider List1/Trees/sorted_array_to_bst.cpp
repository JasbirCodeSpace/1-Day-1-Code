#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;
    Node():left(NULL), right(NULL){};
    Node(int x):data(x), left(NULL), right(NULL){};
};

/*
    Time: O(N)
*/
Node* arrayToBST(int* arr, int l, int r){
    if(l>r)
        return NULL;
    int mid = (l+r)/2;
    Node* root = new Node(arr[mid]);
    root->left = arrayToBST(arr, l, mid-1);
    root->right = arrayToBST(arr, mid+1, r);
    return root;
}

void preOrder(Node* root){
    if(!root)
        return;
    cout<<root->data<<' ';
    preOrder(root->left);
    preOrder(root->right);
}
int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    Node *root = arrayToBST(arr, 0, n-1);
    cout << "PreOrder Traversal of constructed BST \n";
    preOrder(root);
    cout<<endl;

    return 0;
}
