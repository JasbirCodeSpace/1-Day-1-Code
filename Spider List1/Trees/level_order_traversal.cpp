#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
};

Node* newNode(int x){
    Node* node = new Node();
    node->data = x;
    node->left = node->right = NULL;
    return node;
}

int height(Node* root){
    if(root == NULL)
        return 0;
    int lheight = height(root->left);
    int rheight = height(root->right);
    return max(lheight, rheight)+1;
}

void printLevel(Node* root, int level){
    if(root==NULL)
        return;
    if(level==1)
        cout<<root->data<<' ';
    else{
        printLevel(root->left, level-1);
        printLevel(root->right, level-1);
    }
}

/*
    Time complexity: O(N^2) worst case
*/
void printLevelOrder1(Node* root){
    int h = height(root);
    for(int i=1; i<=h; i++)
        printLevel(root, i);
}

/*
    Time: O(N)
    Space: O(N)
*/
void printLevelOrder2(Node* root){
    if(root == NULL)
        return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        while(size--){
            Node* temp = q.front();
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}
int main(int argc, char const *argv[])
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    cout << "Level Order traversal of binary tree is \n";
    printLevelOrder2(root);
    cout<<endl;
    return 0;
}
