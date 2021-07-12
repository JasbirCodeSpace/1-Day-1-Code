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
    node->left = node->right =  NULL;
    return node;
};

int height(Node* root){
    if(!root)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);

    return max(lh, rh)+1;
}

void printCurrentLevel(Node* root, int level){
    if(root == NULL)
        return;
    if(level == 1){
        cout<<root->data<<' ';
        return;
    }
    else if(level>1){
        printCurrentLevel(root->left, level-1);
        printCurrentLevel(root->right, level-1);
    }
}

// T(n) = O(n^2)
void reverseLevelOrder1(Node* root){
    if(!root)
        return;
    int h = height(root);
    for(int i=h; i>=1; i--)
        printCurrentLevel(root, i);
}

/*
    Time: O(N)
    Space: O(N)
*/
void reverseLevelOrder2(Node* root){
    if(!root)
        return;
    
    stack<int> s;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        
        int size = q.size();
        while(size--){
            Node* temp = q.front();
            s.push(temp->data);
            q.pop();
            if(temp->right)
                q.push(temp->right);
            if(temp->left)
                q.push(temp->left);
        }
    }

    while(!s.empty()){
        cout<<s.top()<<' ';
        s.pop();
    }
    cout<<endl;
}
int main(int argc, char const *argv[])
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    cout << "Reverse level Order traversal of binary tree is \n";
    reverseLevelOrder2(root);
    cout<<"\n";
 
    return 0;
}
