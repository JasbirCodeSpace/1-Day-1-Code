#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node():left(NULL), right(NULL){};
    Node(int x):data(x),left(NULL), right(NULL){}; 
};

Node* insert(Node* root, int x){
    Node* temp = new Node(x);
    if(!root)
        return temp;
    if(x<=root->data)
        root->left = insert(root->left, x);
    else if(x>root->data)
        root->right = insert(root->right, x);
    return root;
}
/*
    Time: O(n)
    Space: O(h)
*/
Node* res;
void kthSmallestUtil(Node* root, int k, int& i){
    if(!root)
        return;
    kthSmallestUtil(root->left, k, i);
    if(i==k){
        res = root;
        i++;
        return;
    }else
        i++;
    kthSmallestUtil(root->right, k, i);
}

void kthLargestUtil(Node* root, int k, int& i){
    if(!root)
        return;
    kthLargestUtil(root->right, k, i);
    if(k==i){
        res = root;
        i++;
        return;
    }else
        i++;
    kthLargestUtil(root->left, k, i);
}
/*
    Time: O(k)
    Space: O(h)
*/
Node* kthSmallest(Node* root, int k){
    int i = 1;
    res = NULL;
    kthSmallestUtil(root, k, i);
    return res;
}

/*
    Time: O(k)
    Space: O(h)
*/
Node* kthLargest(Node* root, int k){
    int i = 1;
    res = NULL;
    kthLargestUtil(root, k, i);
    return res;
}
void inOrder(Node* root){
    if(!root)
        return;
    inOrder(root->left);
    cout<<root->data<<' ';
    inOrder(root->right);
}
int main(int argc, char const *argv[])
{
    Node* root = NULL;
    int keys[] = { 20, 8, 22, 4, 12, 10, 14 };
 
    for (int x : keys)
        root = insert(root, x);
 
    int k = 3;
    Node* temp = kthSmallest(root, k);
    cout<<k<<"th smallest element is: "<<temp->data<<endl;
    temp = kthLargest(root, k);
    cout<<k<<"th largest element is: "<<temp->data<<endl;
    return 0;
}
