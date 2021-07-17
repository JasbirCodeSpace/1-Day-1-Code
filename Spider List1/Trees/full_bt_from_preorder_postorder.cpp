#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left, *right;
    Node():left(NULL), right(NULL){};
    Node(int x):data(x), left(NULL), right(NULL){};
};

Node* solve(int* pre, int* post, int l, int h, int &idx, int size){
    if(idx == size || l>h){
        return NULL;
    }
    Node* root = new Node(pre[idx]);
    idx++;
    if(l == h)
        return root;

    int i;
    for(i=l; i<=h; i++){
        if(post[i] == pre[idx])
        break;
    }
    if(i<=h){
        root->left = solve(pre, post, l, i, idx, size);
        root->right = solve(pre, post, i+1, h, idx, size);
    }
    return root;
}

// Time: O(N)
Node* buildTree(int* pre, int* post, int size){
    int idx = 0;
    Node* root = solve(pre, post, 0, size-1, idx, size);
    return root;
}

void inorder(Node* root){
    if(!root)
        return;
    inorder(root->left);
    cout<<root->data<<' ';
    inorder(root->right);
}
int main(int argc, char const *argv[])
{
    int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
    int size = sizeof( pre ) / sizeof( pre[0] );
 
    Node *root = buildTree(pre, post, size);
 
    cout<<"Inorder traversal of the constructed tree: \n";
    inorder(root);
    cout<<endl;
    return 0;
}
