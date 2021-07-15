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

/*
    Time: O(n)
    Space: O(n)
*/

bool checkCompleteBT(Node* root){
    if(!root)
        return true;
    queue<Node*> q;
    q.push(root);
    bool flag = false;

    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp->left){
            if(flag == true)
                return false;
            q.push(temp->left);
        }else{
            flag = true;
        }
        if(temp->right){
            if(flag == true)
                return false;
            q.push(temp->right);
        }else{
            flag = true;
        }
    }
    return true;
    
}
int main(int argc, char const *argv[])
{
    /* Let us construct the following Binary Tree which
        is not a complete Binary Tree
             1
            / \
            2  3
           / \  \
          4   5  6
        */
 
    Node *root = new Node(1);
    root->left     = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
 
    if ( checkCompleteBT(root) == true )
        cout << "Complete Binary Tree";
    else
        cout << "NOT Complete Binary Tree";
    return 0;
}
