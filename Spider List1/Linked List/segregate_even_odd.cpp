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
void segregateEvenOdd(Node** head);

int main(int argc, char const *argv[])
{
    
    Node* head = NULL;
    insert(&head, 11);
    insert(&head, 10);
    insert(&head, 9);
    insert(&head, 6);
    insert(&head, 4);
    insert(&head, 1);
    insert(&head, 0);
  
    printf("\nOriginal Linked list \n");
    printList(head);
  
    segregateEvenOdd(&head);
  
    printf("\nModified Linked list \n");
    printList(head);
    return 0;
}


void insert(Node** head, int x){
    Node *newNode = new Node();
    newNode->data = x;
    newNode->next = *head;
    *head = newNode;

}

void segregateEvenOdd(Node** head){
    Node* oddStart = NULL;
    Node* oddEnd = NULL;
    Node* evenStart = NULL;
    Node* evenEnd = NULL;
    Node* curr = *head;

    while(curr){
        int data = curr->data;
        if(data&1){             // odd
            if(oddStart == NULL){
                oddStart = oddEnd = curr;
            }else{
                oddEnd->next = curr;
                oddEnd = oddEnd->next;
            }
        }else{                  // even
            if(evenStart == NULL){
                evenStart = evenEnd = curr;
            }else{
                evenEnd->next = curr;
                evenEnd = evenEnd->next;
            }
        }
        curr = curr->next;
    }

    if(evenStart == NULL || oddStart == NULL)return;

    oddEnd->next = evenStart;
    evenEnd->next = NULL;

    *head = oddStart;

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
