#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left, *right;
    Node():left(NULL), right(NULL){};
    Node(int x):data(x), left(NULL), right(NULL){};
};

Node* insert(Node* root, int x){
    if(!root)
        return new Node(x);
    if(x < root->data)
        root->left = insert(root->left, x);
    else if(x > root->data)
        root->right = insert(root->right, x);
    return root;
}

void inorder(Node* root){
    if(!root)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void updatePointers(Node* root, Node* &first, Node* &mid, Node* &last, Node* &prev){
    if(!root)
        return;
    updatePointers(root->left, first, mid, last, prev);
    if(prev && root->data < prev->data){
        if(!first){
            first = prev;
            mid = root;
        }else{
            last = root;
        }
    }
    prev = root;
    updatePointers(root->right, first, mid, last, prev);
}

/*
    Time: O(N)
*/
void restoreBST(Node* root){
    if(!root)
        return;
    Node* first, *mid, *last, *prev;
    first = mid = last = prev = NULL;
    updatePointers(root, first, mid, last, prev);

    // case 1: elements not adjacent
    if(first && last){
        swap(first->data, last->data);
    }

    //case 2: elements are adjacent
    else if(first && mid){
        swap(first->data, mid->data);
    }
}
int main(int argc, char const *argv[])
{
      /*  6
        /   \
       10    2
      / \   / \
     1   3 7  12
     10 and 2 are swapped
    */
 
    Node *root = new Node(6);
    root->left        = new Node(10);
    root->right       = new Node(2);
    root->left->left  = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(12);
    root->right->left = new Node(7);
 
    cout <<"Inorder Traversal of the original tree \n";
    inorder(root);
    cout<<endl;
 
    restoreBST(root);
 
    cout <<"\nInorder Traversal of the fixed tree \n";
    inorder(root);
    cout<<endl;
    return 0;
}
