#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;
    Node():left(NULL), right(NULL){};
    Node(int x): data(x), left(NULL), right(NULL){};
};

/*
    Time: O(N)
*/
void serialize(Node* root, FILE* fp){
    if(!root){
        fprintf(fp, "%d ", -1);
        return;
    }
    fprintf(fp, "%d ", root->data);
    serialize(root->left, fp);
    serialize(root->right, fp);
}

/*
    Time: O(N)
*/

Node* deserialize(FILE* fp){
    int val;
    if(!fscanf(fp, "%d ", &val) || val == -1)
        return NULL;
    Node* root = new Node(val);
    root->left = deserialize(fp);
    root->right = deserialize(fp);
    return root;

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
    Node *root        = new Node(20);
    root->left               = new Node(8);
    root->right              = new Node(22);
    root->left->left         = new Node(4);
    root->left->right        = new Node(12);
    root->left->right->left  = new Node(10);
    root->left->right->right = new Node(14);

    FILE* fp = fopen("tree.txt", "w+");
    serialize(root, fp);
    cout<<"Serialized binary tree data into tree.txt"<<endl;
    fclose(fp);

    fp = fopen("tree.txt", "r");
    Node* res = deserialize(fp);
    cout<<"Inorder of deserialized binary tree: ";
    inorder(res);
    cout<<endl;
    fclose(fp);

    return 0;
}
