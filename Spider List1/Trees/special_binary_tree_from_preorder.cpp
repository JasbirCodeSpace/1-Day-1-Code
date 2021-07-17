#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left, *right;
    Node():left(NULL), right(NULL){};
    Node(int x):data(x), left(NULL), right(NULL){};
};

Node* solve(int* pre, char* preNL, int &idx, int size){
    if(idx >= size)
        return NULL;
    Node* root = new Node(pre[idx++]);
    
    if(preNL[idx-1] == 'N'){
        root->left = solve(pre, preNL, idx, size);
        root->right = solve(pre, preNL, idx, size);
    }
    return root;
}

/*
    Time: O(N)
*/
Node* buildTree(int* pre, char* preNL, int size){

    int idx = 0;
    Node* root = solve(pre, preNL, idx, size);
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
 
    /* Constructing tree given in the above figure
          10
         /  \
        30   15
       /  \
      20   5 
    */
    int pre[] = {10, 30, 20, 5, 15};
    char preLN[] = {'N', 'N', 'L', 'L', 'L'};
    int n = sizeof(pre)/sizeof(pre[0]);

    Node* root = buildTree (pre, preLN, n);
 
    printf("Following is Inorder Traversal of the Constructed Binary Tree: \n");
    inorder(root);
    cout<<endl;

    return 0;
}
