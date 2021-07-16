#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left, *right;
    Node():left(NULL), right(NULL){};
    Node(int x):data(x), left(NULL), right(NULL){};
};

// Time: O(N)
bool pathExist(Node* root, int sum){
    if(!root)
        return false;
    if(!root->left && !root->right && sum == root->data){
        return true;
    }
    return pathExist(root->left, sum-root->data)||pathExist(root->right, sum-root->data);
}

// Time: O(N)

void _printKsumPaths(Node* root, int k, vector<int>& arr){
    if(!root)
        return;
    arr.push_back(root->data);
    if(k == root->data){
        for(int x: arr){
            cout<<x<<" ";
        }
        cout<<endl;
        return;
    }
    if(root->left)
        _printKsumPaths(root->left, k-root->data, arr);
    if(root->right)
        _printKsumPaths(root->right, k-root->data, arr);
    arr.pop_back();
}
void printKsumPaths(Node* root, int k){
    if(!root)
        return;
    vector<int> arr;
    _printKsumPaths(root, k, arr);
}
int main(int argc, char const *argv[])
{
int sum = 21;
     
    /* Constructed binary tree is
                  10
                /    \
               8      2
              / \    /
             3   5  2
    */
    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(2);
     
    if(pathExist(root, sum))
        cout << "There is a root-to-leaf path with sum " << sum;
    else
        cout << "There is no root-to-leaf path with sum " << sum;
    cout<<endl;

    printKsumPaths(root, sum);

    return 0;
}
