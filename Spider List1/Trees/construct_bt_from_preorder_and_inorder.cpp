#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    char data;
    Node* left, *right;
    Node():left(NULL), right(NULL){};
    Node(int x):data(x), left(NULL), right(NULL){};
};

int idx = 0;
unordered_map<char, int> m;
Node* solve(char* pre, char* in, int l, int h){
    if( l>h)
        return NULL;
    
    Node* root = new Node(pre[idx++]);
    if(l==h)
        return root;
    int mid = m[root->data];


    root->left = solve(pre, in, l, mid-1);
    root->right = solve(pre, in, mid+1, h);
    return root;
    
}
/*
    Time: O(N)
    Space: O(N)
*/
Node* buildTree(char* pre, char* in, int size){
    
    for(int i=0; i<size; i++)
        m[in[i]] = i;
    
    Node* root = solve(pre, in, 0, size-1);
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
    char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
    int len = sizeof(in) / sizeof(in[0]);
    Node* root = buildTree(pre, in, len);
 
    cout << "Inorder traversal of the constructed tree is \n";
    inorder(root);
    cout<<endl;

    return 0;
}
