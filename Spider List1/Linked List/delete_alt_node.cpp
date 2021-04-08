#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void insert(Node** head, int x);
void printList(Node* head);

/*  Time complexity: O(N) */
void deleteAltNode1(Node** head);
void deleteAltNode2(Node** head);
int main(int argc, char const *argv[])
{
    /* Start with the empty list */
    Node* head = NULL;
 
    /* Using insert() to construct below list
    1->2->3->4->5 */
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);
 
    cout<<"List before calling deleteAltNode() \n";
    printList(head);
 
    deleteAltNode2(&head);
 
    cout<<"\nList after calling deleteAltNode() \n";
    printList(head);
    return 0;
}

void deleteAltNode1(Node** head){

    if(head == NULL)return;

    Node *curr = *head;
    Node *next = curr->next;
    while(curr && next){
        curr->next = next->next;
        free(next);
        curr = curr->next;
        if(curr == NULL)return;
        next = curr->next;
    }
}

void deleteAltNode2(Node** head){
    if(*head == NULL)return;
    Node* next = (*head)->next;
    if(next == NULL)return;

    (*head)->next = next->next;
    free(next);
    next = (*head)->next;
    deleteAltNode2(&next);
}
void insert(Node** head, int x){
    Node *newNode = new Node();
    newNode->data = x;
    newNode->next = *head;
    *head = newNode;

}

void printList(Node* head){

    while(head){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<'\n';
}