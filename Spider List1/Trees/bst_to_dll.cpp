#include<iostream>
using namespace std;

class TNode{
    public:
    int data;
    TNode* left, *right;
    TNode():left(NULL), right(NULL){};
    TNode(int x):data(x), left(NULL), right(NULL){};
};

class LNode{
    public:
    int data;
    LNode* prev, *next;
    LNode():prev(NULL), next(NULL){};
    LNode(int x):data(x), prev(NULL), next(NULL){};
};

void _bst2dll(TNode* root, LNode* &head, LNode* &prev){
    if(!root)
        return;
    _bst2dll(root->left, head, prev);
    LNode* temp = new LNode(root->data);
    if(!prev){
        head = temp;
    }else{   
        prev->next = temp;
        temp->prev = prev;
    }
    prev = temp;
    _bst2dll(root->right, head, prev);
}

/*
    Time: O(N)
    Not in place
*/
LNode* bst2dll(TNode* root){
    if(!root)
        return NULL;
    LNode* head, *prev;
    head = prev = NULL;
    _bst2dll(root, head, prev);
    return head;
}

void printList(LNode* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
int main(int argc, char const *argv[])
{
    TNode* root = new TNode(10);
    root->left = new TNode(12);
    root->right = new TNode(15);
    root->left->left = new TNode(25);
    root->left->right = new TNode(30);
    root->right->left = new TNode(36);
 
    LNode* head = bst2dll(root);
 
    printList(head);
    return 0;
}
