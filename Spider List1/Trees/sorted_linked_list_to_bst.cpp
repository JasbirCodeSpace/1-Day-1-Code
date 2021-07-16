#include<iostream>
using namespace std;

class LNode{
    public:
    int data;
    LNode* next;
    LNode():next(NULL){};
    LNode(int x):data(x), next(NULL){};
};

class TNode{
    public:
    int data;
    TNode* left, *right;
    TNode():left(NULL), right(NULL){};
    TNode(int x):data(x), left(NULL), right(NULL){};
};

void push(LNode* &head, int x){
    LNode* node = new LNode(x);
    if(!head){
        head = node;
        return;
    }else{
        node->next = head;
        head = node;
        return;
    }
}

void printList(LNode* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

void preOrder(TNode* root){
    if(!root)
        return;
    cout<<root->data<<' ';
    preOrder(root->left);
    preOrder(root->right);
}
int countNodes(LNode* head){
    int count = 0;
    while(head){
        head = head->next;
        count++;
    }
    return count;
}

TNode* _sortedListToBST(LNode* &head, int n){
    if(n<=0)
        return NULL;
    TNode* left = _sortedListToBST(head, n/2);

    TNode* root = new TNode(head->data);
    root->left = left;
    head = head->next;

    TNode* right = _sortedListToBST(head, n-n/2-1);
    root->right = right;
    return root;
}
TNode* sortedListToBST(LNode* head){
    if(!head)
        return NULL;
    int n = countNodes(head);
    TNode* root = _sortedListToBST(head, n);
    return root;
}
int main(int argc, char const *argv[])
{
    LNode* head = NULL;
 
    push(head, 7);
    push(head, 6);
    push(head, 5);
    push(head, 4);
    push(head, 3);
    push(head, 2);
    push(head, 1);
 
    cout<<"Given Linked List ";
    printList(head);
 
    TNode *root = sortedListToBST(head);
    cout<<"\nPreOrder Traversal of constructed BST ";
    preOrder(root);
    cout<<endl;
    return 0;
}
