#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void insert(Node** head, int x);
void printList(Node* head);

/* Time complexity: O(n) */
void rotate1(Node** head, int k);
void rotate2(Node** head, int k);
int main(int argc, char const *argv[])
{
    Node* head = NULL;
    for (int i = 10; i > 0; i -= 1)
        insert(&head, i);
 
    cout << "Given linked list \n";
    printList(head);
    rotate2(&head, 4);
 
    cout << "\nRotated Linked list \n";
    printList(head);   
    return 0;
}

void rotate1(Node** head, int k){
    if(head == NULL)return;

    Node* curr = *head;
    Node* kthNode = NULL;
    int count = 1;

    while(count<k && curr){
        curr = curr->next;
        count++;
    }

    if(curr == NULL)return;

    kthNode = curr;
    while(curr->next){
        curr = curr->next;
    }

    curr->next = *head;
    *head = kthNode->next;
    kthNode->next = NULL;
}

void rotate2(Node** head, int k){
    if(head == NULL) return;

    Node* curr = *head;
    while(curr->next){
        curr = curr->next;
    }
    curr->next = *head;

    curr = *head;
    for (int i = 1; i < k; i++)
    {
       curr = curr->next; 
    }
    *head = curr->next;
    curr->next = NULL;
    
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