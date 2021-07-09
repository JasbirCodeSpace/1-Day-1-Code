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
    Time complexity: O(n)
    Space complexity: O(n/k)
*/
Node* reverseKGroup1(Node* head, int k);

/*
    Time complexity: O(n)
    Space complexity: O(k)
*/
Node* reverseKGroup2(Node* head, int k);

int main(int argc, char const *argv[])
{
    Node* head = NULL;
    for (int i = 10; i > 0; i -= 1)
        insert(&head, i);
 
    cout << "Given linked list \n";
    printList(head);
    head = reverseKGroup2(head, 3);
 
    cout << "\nReversed Linked list \n";
    printList(head);   
    return 0;
}

/*
    Time complexity: O(N)
    Space complexity: O(N/K)
*/
Node* reverseKGroup1(Node* head, int k){

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
        head->next = reverseKGroup1(next, k);
        
    return prev;
    
}

/*
    Time complexity: O(N)
    Space complexity: O(K)
*/
Node* reverseKGroup2(Node* head, int k ){
    stack<Node*> stk;
    Node* curr = head;
    Node* prev = NULL;
    while(curr){
        int i = 0;
        while(curr && i<k){
            stk.push(curr);
            curr = curr->next;
            i++;
        }
        while(!stk.empty()){
            if(prev == NULL){
                prev = stk.top();
                head = prev;
            }else{
                prev->next = stk.top();
                prev = prev->next;
            }
            stk.pop();
        }
    }
    prev->next = NULL;
    return head;
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