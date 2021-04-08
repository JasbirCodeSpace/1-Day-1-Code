#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void insert(Node** head, int x);
void printList(Node* head);
Node* reverseKGroup(Node* head, int k);

int main(int argc, char const *argv[])
{
    Node* head = NULL;
    for (int i = 10; i > 0; i -= 1)
        insert(&head, i);
 
    cout << "Given linked list \n";
    printList(head);
    head = reverseKGroup(head, 3);
 
    cout << "\nReversed Linked list \n";
    printList(head);   
    return 0;
}

/*
    Time complexity: O(N)
    Space complexity: O(N/K)
*/
Node* reverseKGroup(Node* head, int k){

    Node *prev = NULL, *next = NULL, *curr = head;
    int i=0;
    while (i<k && curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        i++;
    }

    if(next)
        head->next = reverseKGroup(next, k);
        
    return prev;
    
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