#include<iostream>
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

Node* insert(Node* root, int x){
    if(!root)
        return newNode(x);
    else{
        if(x <= root->data)
            root->left = insert(root->left, x);
        else if(x>root->data)
            root->right = insert(root->right, x);
        return root;
    }
}

void _addValues(Node* root, int& sum){
    if(!root)
        return;
    _addValues(root->right, sum);
    sum += root->data;
    root->data = sum;
    _addValues(root->left, sum);
}
// T(n) = O(n)
void addValues(Node* root){
    int sum = 0;
    _addValues(root, sum);
}

void inorder(Node* root){
    if(!root)
        return;
    inorder(root->left);
    cout<<root->data<<' ';
    inorder(root->right);
}
int main(int argc, char const *argv[])
{
  /* Let us create following BST
                50
              /    \
            30      70
           /  \     /  \
          20   40 60    80 
*/
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
 
    addValues(root);
 
    // print inoder traversal of the modified BST
    inorder(root);
    cout<<endl;
    return 0;
}
