#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node* next;
};

Node* newNode(int x){
    Node* node = new Node();
    node->data = x;
    node->left = node->right = node->next = NULL;
    return node;
};

int height(Node* root){
    if(!root)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);

    return max(lh, rh)+1;
}

void printCurrentLevel(Node* root, int level, bool ltr){
    if(root == NULL)
        return;
    if(level==1){
        cout<<root->data<<" ";
    }else if(level>1){
        if(ltr){
            printCurrentLevel(root->left, level-1, ltr);
            printCurrentLevel(root->right, level-1, ltr);
        }else{
            printCurrentLevel(root->right, level-1, ltr);
            printCurrentLevel(root->left, level-1, ltr);
        }
    }
}

// T(n) = O(n^2) worst case
void spiralLevelOrder1(Node* root){
    if(!root)
        return;
    
    bool ltr = false;
    int h = height(root);

    for(int i=1; i<=h; i++){
        printCurrentLevel(root, i, ltr);
        ltr = !ltr;
    }
}

/*
    Time: O(N)
    Space: O(N)
*/
void spiralLevelOrder2(Node* root){
    if(!root)
        return;
    
    stack<Node*> s1;        // right to left
    stack<Node*> s2;        // left to right

    bool ltr = false;
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            Node* temp = s1.top();
            s1.pop();
            cout<<temp->data<<" ";
            if(temp->right)
                s2.push(temp->right);
            if(temp->left)
                s2.push(temp->left);
        }
        while(!s2.empty()){
            Node* temp = s2.top();
            s2.pop();
            cout<<temp->data<<" ";
            if(temp->left)
                s1.push(temp->left);
            if(temp->right)
                s1.push(temp->right);
        }
    }
}
int main(int argc, char const *argv[])
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    printf("Spiral Order traversal of "
           "binary tree is \n");
            
    spiralLevelOrder2(root);
    printf("\n");

    return 0;
}
