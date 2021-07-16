#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left, *right;
    Node():left(NULL), right(NULL){};
    Node(int x):data(x), left(NULL), right(NULL){};
};

/*
    Time: O(N)
*/
void printInRange(Node* root, int min, int max){
    if(!root)
        return;
    printInRange(root->left, min, max);
    if(root->data >= min && root->data <= max)
        cout<<root->data<<" ";
    printInRange(root->right, min, max);
}
int main(int argc, char const *argv[])
{
    Node *root = new Node();
    int k1 = 10, k2 = 25;
     
    root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
     
    printInRange(root, k1, k2);
    cout<<endl;
    return 0;
}
