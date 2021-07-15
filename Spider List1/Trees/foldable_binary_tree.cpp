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

bool isFoldableUtil(Node* root1, Node* root2){
    if(!root1 && !root2)
        return true;
    if(!root1 || !root2)
        return false;
    return isFoldableUtil(root1->left, root2->right)&&isFoldableUtil(root1->right, root2->left);
}
/*
    Time: O(N)
*/
bool isFoldable1(Node* root){
    if(!root)
        return true;
    return isFoldableUtil(root->left, root->right);
}

/*
    Time: O(n)
    Space: O(n)
*/
bool isFoldable2(Node* root){
    if(!root)
        return true;
    queue<Node*> q;
    q.push(root->left);
    q.push(root->right);

    while(!q.empty()){
        Node* root1 = q.front();
        q.pop();
        Node* root2 = q.front();
        q.pop();
        if(!root1 && !root2)
            continue;
        if(!root1 || !root2)
            return false;
        
        q.push(root1->left);
        q.push(root2->right);
        q.push(root1->right);
        q.push(root2->left);

    }
    return true;
}
int main(int argc, char const *argv[])
{
       /* The constructed binary tree is
              1
            /   \
           2     3
            \   /
             4 5
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->left->right = new Node(5);
 
    if (isFoldable2(root)) {
        cout << "tree is foldable";
    }
    else {
        cout << "\ntree is not foldable";
    }
    cout<<endl;
    return 0;
}
