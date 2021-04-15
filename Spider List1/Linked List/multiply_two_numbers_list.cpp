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
    Time Complexity: O(M+N)
    Space Complexity: O(1)
*/
double mulTwoList(Node *a, Node *b);
int main(int argc, char const *argv[])
{
    Node *head1 = NULL, *head2 = NULL; 
   
    int arr1[] = {5, 6, 7}; 
    int arr2[] = {1, 8}; 
   
    int size1 = sizeof(arr1) / sizeof(arr1[0]); 
    int size2 = sizeof(arr2) / sizeof(arr2[0]); 
   
    int i; 
    for (i = size1-1; i >= 0; --i) 
        insert(&head1, arr1[i]); 
   
    for (i = size2-1; i >= 0; --i) 
        insert(&head2, arr2[i]); 
    
    printList(head1);
    printList(head2);
    double result=mulTwoList(head1, head2);
    cout<<"Product = "<<result<<endl;   
    return 0;
}

double mulTwoList(Node *a, Node *b){
    double x = 0, y = 0;
    while(a){
        x = x*10 + a->data;
        a = a->next;
    }
    while(b){
        y = y*10 + b->data;
        b = b->next;
    }
    return x*y;
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