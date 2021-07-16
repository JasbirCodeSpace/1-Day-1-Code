#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left, *right;
    Node():left(NULL), right(NULL){};
    Node(int x):data(x), left(NULL), right(NULL){};
};

void printPathsUtil(Node* root, vector<vector<int>>& res, vector<int> arr){
    if(!root)
        return;
    arr.push_back(root->data);
    if(!root->left && !root->right){
        res.push_back(arr);
        return;
    }
    if(root->left)
        printPathsUtil(root->left, res, arr);
    if(root->right)
        printPathsUtil(root->right, res, arr);
}

/*
    Time: O(N)
*/
vector<vector<int>> printPaths(Node* root){
    vector<vector<int>> res;
    if(!root)
        return res;
    vector<int> arr;
    printPathsUtil(root, res, arr);
    return res;
}
int main(int argc, char const *argv[])
{
    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(2);

   vector<vector<int>> final=printPaths(root);
  
   for(int i=0;i<final.size();i++)
   {
        
       for(int j=0;j<final[i].size();j++)
            cout<<final[i][j]<<" ";
        cout<<endl;
   }
    return 0;
}
