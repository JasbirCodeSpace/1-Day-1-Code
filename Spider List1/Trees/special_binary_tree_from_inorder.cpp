#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left, *right;
    Node():left(NULL), right(NULL){};
    Node(int x):data(x), left(NULL), right(NULL){};
};

int max(int* arr, int l, int h){
    int res = INT_MIN;
    int i=0, idx=-1;
    for(i=l;i<=h;i++){
        if(arr[i] > res){
            res = arr[i];
            idx = i;
        }
    }
    return idx;
}
Node* solve(int* in, int l, int h){
    if(l>h)
        return NULL;

    int i = max(in, l, h);
    Node* root = new Node(in[i]);
    if(l==h)
        return root;
    root->left = solve(in, l, i-1);
    root->right = solve(in, i+1, h);
    return root;
    
}

/*
    Time: O(N^2)
*/
Node* buildTree(int* in, int size){
    Node* root = solve(in, 0, size-1);
    return root;
}

void inorder(Node* root){
    if(!root)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(int argc, char const *argv[])
{
     /* Assume that inorder traversal of following tree is given
             40
           /    \
         10     30
        /         \
       5           28 
*/
 
    int in[] = {5, 10, 40, 30, 28};
    int len = sizeof(in)/sizeof(in[0]);
    Node *root = buildTree(in, len);
 
    cout << "Inorder traversal of the constructed tree is \n";
    inorder(root);
    cout<<endl;
    return 0;
}
