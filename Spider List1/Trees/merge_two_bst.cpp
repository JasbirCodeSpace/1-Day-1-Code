#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;
    Node():left(NULL), right(NULL){};
    Node(int x):data(x), left(NULL), right(NULL){};
};

void inorder(Node* root, vector<int>& a){
    if(!root)
        return;
    inorder(root->left, a);
    a.push_back(root->data);
    inorder(root->right, a);
}
vector<int> merge(vector<int>& a, vector<int>& b){
    vector<int> res;
    int m=a.size();
    int n = b.size();
    int i=0, j=0;
    while(i<m && j<n){
        if(a[i]<=b[j]){
            res.push_back(a[i]);
            i++;
        }else{
            res.push_back(b[j]);
            j++;
        }
    }
    
    while(i<m){
        res.push_back(a[i]);
        i++;
    }
    while(j<n){
        res.push_back(b[j]);
        j++;
    }
    return res;
}
vector<int> merge(Node *root1, Node *root2)
{
    vector<int> a, b;
    inorder(root1, a);
    inorder(root2, b);
    vector<int> res = merge(a, b);
    return res;
}

int main(int argc, char const *argv[])
{
    Node *root1 = new Node(100);
    root1->left     = new Node(50);
    root1->right = new Node(300);
    root1->left->left = new Node(20);
    root1->left->right = new Node(70);

    Node *root2 = new Node(80);
    root2->left     = new Node(40);
    root2->right = new Node(120);
 
    vector<int> res = merge(root1, root2);
 
    cout << "Following is Inorder traversal of the merged tree \n";
    for(int x: res){
        cout<< x<<" ";
    }
    cout<<endl;
    return 0;
}
