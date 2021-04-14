#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void insert(Node** head, int x);
void printList(Node* head);

/*
    Time complexity: O(N)
    Space complexity: O(1)
*/
void splitAlternateNodes(Node *head, Node **a, Node **b);
int main(int argc, int const *argv[])
{

    Node* head = NULL;
    Node* a = NULL;
    Node* b = NULL;
     
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);                                
    insert(&head, 0);
     
    cout<<"Original linked List: ";
    printList(head);
     
    splitAlternateNodes(head, &a, &b);
     
    cout<<"\nResultant Linked List 'a' : ";
    printList(a);        
     
    cout<<"\nResultant Linked List 'b' : ";
    printList(b); 
    return 0;
}
void splitAlternateNodes(Node *head, Node **a, Node **b){

    Node* curr = head;
    Node *aHead = NULL, *aTail = NULL;
    Node *bHead = NULL, *bTail = NULL;

    if(curr){
        if(aHead == NULL){
            aHead = aTail = curr;
        }
        curr = curr->next;
        if(bHead == NULL){
            bHead = bTail = curr;
            curr = curr->next;
        }
    }
    while(curr){

        aTail->next = curr;
        aTail = aTail->next;
        curr = curr->next;

        if(curr){
            bTail->next = curr;
            bTail = bTail->next;
            curr = curr->next;
        }
    }

    aTail->next = bTail->next = NULL;
    *a = aHead;
    *b = bHead;
}

void insert(Node** head, int x){
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = *head;
    *head = newNode;
}

void printList(Node* head){

    while(head){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}
