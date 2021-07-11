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
}
void populateInorder(Node* root, Node* &prev){
    if(root == NULL)
        return;
    populateInorder(root->left, prev);
    if(prev){
        prev->next = root;
    }
    prev = root;
    populateInorder(root->right, prev);
}

/*
    Time complexity: O(N)
*/
void populateNext1(Node* root){
    Node* prev = NULL;
    populateInorder(root, prev);
}

void inOrder(Node* root, vector<Node*> &t){
    if(root == NULL)
        return;
    inOrder(root->left, t);
    t.push_back(root);
    inOrder(root->right, t);
}

/*
    Time : O(N)
    Space: O(N)
*/
void populateNext2(Node* root){
    vector<Node*> t;
    inOrder(root, t);

    int i=0;
    for(i=0; i<t.size()-1; i++)
        t[i]->next = t[i+1];
    t[i]->next = NULL;
    
}
int main(int argc, char const *argv[])
{
  /* Constructed binary tree is
            10
            / \
        8       12
        /
    3
    */
    Node *root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(12);
    root->left->left = newNode(3);
 

    populateNext2(root);
 

    Node *ptr = root->left->left;
    while(ptr)
    {
        // -1 is printed if there is no successor
        cout << "Next of " << ptr->data << " is "
             << (ptr->next? ptr->next->data: -1)
             << endl;
        ptr = ptr->next;
    }
 
    return 0;
}
