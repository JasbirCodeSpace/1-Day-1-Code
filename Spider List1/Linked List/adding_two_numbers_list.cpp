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
    Space Complexity: O(M+N)
*/
Node* addTwoList(Node *a, Node *b);
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
    Node* result=addTwoList(head1, head2);
    printList(result);    
    return 0;
}

Node* addTwoList(Node *a, Node *b){
    stack<int> s1, s2;
    while(a){
        s1.push(a->data);
        a = a->next;
    }
    while(b){
        s2.push(b->data);
        b = b->next;
    }

    int x = 0, y = 0, carry = 0;
    Node *result = NULL;
    while(!s1.empty() || !s2.empty()){
        x = 0; y = 0;
        if(!s1.empty()){
            x = s1.top();
            s1.pop();
        }
        if(!s2.empty()){
            y = s2.top();
            s2.pop();
        }

        int sum = x + y + carry;
        carry = sum / 10;
        sum = sum%10;
        insert(&result, sum);
    }
    if(carry!=0){
        insert(&result, carry);
    }
    return result;
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