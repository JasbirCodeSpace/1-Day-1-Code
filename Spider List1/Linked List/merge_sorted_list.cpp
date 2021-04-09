#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void insert(Node** head, int x);
void printList(Node* head);

/* Time complexity: O(M+N) */
Node* mergeSortedList1(Node* head1, Node* head2);
Node* mergeSortedList2(Node* head1, Node* head2);

int main(int argc, char const *argv[])
{
    Node* res = NULL; 
    Node* a = NULL; 
    Node* b = NULL; 
  
    insert(&a, 15); 
    insert(&a, 10); 
    insert(&a, 5); 
  
    insert(&b, 20); 
    insert(&b, 3); 
    insert(&b, 2); 
  
    res = mergeSortedList2(a, b); 
    
    cout << "Merged Linked List is: \n"; 
    printList(res);  
    return 0;
}

Node* mergeSortedList1(Node* head1, Node* head2){
    Node *head=NULL, *tail = NULL;

    while(head1 && head2){
        Node* newNode = new Node();
        newNode->next = NULL;
        if(head == NULL)head = newNode;
        else tail->next = newNode;
        tail = newNode;

        if(head1->data <= head2->data){
            newNode->data = head1->data;
            head1 = head1->next;
        }else{
            newNode->data = head2->data;
            head2 = head2->next;
        }
    }

    while(head1){
        Node* newNode = new Node();
        newNode->data = head1->data;
        tail->next = newNode;
        tail = newNode;
        head1 = head1->next;
    }
    while(head2){
        Node* newNode = new Node();
        newNode->data = head2->data;
        tail->next = newNode;
        tail = newNode;
        head2 = head2->next;    
    }

    return head;

}

Node* mergeSortedList2(Node* head1, Node* head2){
    Node* result = NULL;

    if(head1 == NULL)return head2;
    if(head2 == NULL)return head1;

    if(head1->data <= head2->data){
        result = head1;
        result->next = mergeSortedList2(head1->next, head2);
    }else{
        result = head2;
        result->next = mergeSortedList2(head1, head2->next);       
    }

    return result;
}
void insert(Node** head, int x){
    Node *newNode = new Node();
    newNode->data = x;
    newNode->next = *head;
    *head = newNode;

}

bool isNodePresent(Node* head, int x){
    while(head){
        if(head->data == x)return true;
        head = head->next;
    }
    return false;
}
void printList(Node* head){

    while(head){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<'\n';
}