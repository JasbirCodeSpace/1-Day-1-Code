#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* prev, *next;
    Node():prev(NULL), next(NULL){};
    Node(int x):data(x), prev(NULL), next(NULL){};
};

int countNodes(Node* head){
    int count = 0;
    while(head){
        count++;
        head = head->next;
    }
    return count;
}

Node* _dll2bst(Node* &head, int n){
    if(n<=0)
        return NULL;
    Node* left = _dll2bst(head, n/2);

    Node* root = head;
    root->prev = left;
    head = head->next;
    
    Node* right= _dll2bst(head, n-n/2-1);
    root->next = right;

    return root;
}

/*
    Time: O(N)
    In Place
*/
Node* dll2bst(Node* head){
    if(!head)
        return NULL;
    int n = countNodes(head);
    Node* root =  _dll2bst(head, n);
    return root;
}


void push(Node* &head, int x){
    Node* node = new Node(x);
    if(!head){
        head = node;
        return;
    }else{
        head->prev = node;
        node->next = head;
        head = node;
    }
}

void printList(Node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

void preOrder(Node* root){
    if(!root)
        return;
    cout<<root->data<<" ";
    preOrder(root->prev);
    preOrder(root->next);
}
int main(int argc, char const *argv[])
{
    Node* head = NULL;
 
    push(head, 7);
    push(head, 6);
    push(head, 5);
    push(head, 4);
    push(head, 3);
    push(head, 2);
    push(head, 1);
 
    cout<<"Given Linked List\n";
    printList(head);
 
    Node *root = dll2bst(head);
    cout<<"\nPreOrder Traversal of constructed BST \n ";
    preOrder(root);
    cout<<endl;
    
    return 0;
}
