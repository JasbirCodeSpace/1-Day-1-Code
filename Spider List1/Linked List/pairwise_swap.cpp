#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void insert(Node **head, int x);
void printList(Node *head);
/*
    Swapping data values
    Time Complexity: O(N)
*/
void pairwiseSwap1(Node **head);
/*
    Changing links
    Time Complexity: O(N)
*/
Node* pairwiseSwap2(Node *head);
int main(int argc, char const *argv[])
{
    Node* start = NULL;
  
    insert(&start, 5);
    insert(&start, 4);
    insert(&start, 3);
    insert(&start, 2);
    insert(&start, 1);
  
    cout << "Linked list "
         << "before calling pairWiseSwap()\n";
    printList(start);
  
    start = pairwiseSwap2(start);
  
    cout << "\nLinked list "
         << "after calling pairWiseSwap()\n";
    printList(start);   
    return 0;
}

void pairwiseSwap1(Node **head){
    Node *curr = *head;
    while(curr && curr->next){
        swap(curr->data, curr->next->data);
        curr = curr->next->next;
    }
}

Node* pairwiseSwap2(Node *head){
    if(head == NULL || head->next == NULL)return head;
    Node* curr = head->next;
    Node *prev = head;
    head = curr;
    while(true){
        Node *next = curr->next;
        curr->next = prev;
        if(next==NULL || next->next == NULL){
            prev->next = next;
            break;
        }
        prev->next = next->next;
        prev = next;
        curr = prev->next;
    }
    return head;
}

void insert(Node **head, int x){
    Node *newNode = new Node();
    newNode->data = x;
    newNode->next = *head;
    *head = newNode;
}

void printList(Node *head){
    while(head){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}