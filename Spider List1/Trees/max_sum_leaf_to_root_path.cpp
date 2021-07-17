#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;
    Node():left(NULL), right(NULL){};
    Node(int x): data(x), left(NULL), right(NULL){};
};

int max_sum = INT32_MIN;
Node* node = NULL;
void maxSumPath(Node* root, int sum){
    if(!root)
        return;
    if(!root->left && !root->right && root->data+sum > max_sum){
        node = root;
        max_sum = sum + root->data;
        return;
    }
    maxSumPath(root->left, sum+root->data);
    maxSumPath(root->right, sum+root->data);
}

bool printPath(Node* root){
    if(!root)
        return false;
    if(root == node || printPath(root->left) || printPath(root->right)){
        cout<<root->data<<' ';
        return true;
    }
    return false;
}
int main(int argc, char const *argv[])
{
    Node* root = NULL;
  
    root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(7);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
  
    cout << "Following are the nodes on the maximum "
            "sum path \n";
    maxSumPath(root, 0);
    printPath(root);
    
    cout<<endl;

    cout << "\nSum of the nodes is " << max_sum<<endl;
    return 0;
}
