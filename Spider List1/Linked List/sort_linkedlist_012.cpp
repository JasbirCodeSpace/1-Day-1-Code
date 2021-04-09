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
void sortList(Node** head);

int main(int argc, char const *argv[])
{
    Node *head = NULL; 
    insert(&head, 0); 
    insert(&head, 1); 
    insert(&head, 0); 
    insert(&head, 2); 
    insert(&head, 1); 
    insert(&head, 1); 
    insert(&head, 2); 
    insert(&head, 1); 
    insert(&head, 2); 
  
    cout << "Linked List Before Sorting\n"; 
    printList(head); 
  
    sortList(&head); 
  
    cout << "Linked List After Sorting\n"; 
    printList(head);   
    return 0;
}

void sortList(Node** head){

    Node* curr = *head;
    int count[3] = {0, 0, 0};

    while(curr){
        count[curr->data]++;
        curr = curr->next;
    }

    curr = *head;
    int i=0;
    while(curr){
        if(count[i]==0)i++;
        curr->data = i;
        count[i]--;
        curr = curr->next;
    }

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
