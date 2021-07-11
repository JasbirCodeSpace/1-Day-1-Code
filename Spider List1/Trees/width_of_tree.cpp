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
int getLevelWidth(Node* root, int level){
    if(root == NULL)
        return 0;
    if(level == 1)
        return 1;
    else{
        return getLevelWidth(root->left, level-1)+getLevelWidth(root->right, level-1);
    }
}
/*
    Time complexity: O(N^2) worst case
    Space: O(N) worst case
*/
int getMaxWidth1(Node* root){

    int width = 0;
    int h = height(root);
    for(int i=1; i<=h; i++){
        width = max(width, getLevelWidth(root, i));
    }
    return width;
}

/*
    Time complexity: O(N)
    Space complexity: O(N)
*/
int getMaxWidth2(Node* root){

    if(root==NULL)
        return 0;
    
    int width = 0;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        width = max(width, size);

        while(size--){
            Node* temp = q.front();
            q.pop();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    return width;
}
int main(int argc, char const *argv[])
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(8);
    root->right->right->left = newNode(6);
    root->right->right->right = newNode(7);
 
    cout << "Maximum width of the given binary tree is " << getMaxWidth2(root)<<endl;
    return 0;
}
