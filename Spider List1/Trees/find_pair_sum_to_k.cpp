#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
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

void findPair1Util(Node* root, int k, bool& f, unordered_set<int>& s){
    if(!root || f)
        return;
    if(s.find(k-root->data) != s.end()){
        f = true;
        cout << "Pair is found (" << k - root->data<< ", " << root->data << ")" << endl;
        return;
    }else
        s.insert(root->data);
    findPair1Util(root->left, k, f, s);
    findPair1Util(root->right, k, f, s);
}

/*
    Time: O(N)
    Space: O(N)
*/
bool findPair1(Node* root, int k){
    unordered_set<int> s;
    bool f = false;
    findPair1Util(root, k, f, s);
    return f;
}

void inorder(Node* root, vector<int>& arr){
    if(!root)
        return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}
/*
    Time: O(N)
    Space: O(N)
*/
bool findPair2(Node* root, int k){
    if(!root)
        return false;
    vector<int> arr;
    inorder(root, arr);
    int l = 0, r = arr.size()-1;
    while (l<r)
    {
        int sum = arr[l]+arr[r];
        if(sum == k)
            return true;
        else if(sum > k)
            r--;
        else
            l++;
    }
    return false;
}
int main(int argc, char const *argv[])
{
    Node* root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 12);
    root = insert(root, 16);
    root = insert(root, 25);
    root = insert(root, 10);
 
    int sum = 33;
    cout<<findPair2(root, sum);
    cout<<endl;
    return 0;
}
