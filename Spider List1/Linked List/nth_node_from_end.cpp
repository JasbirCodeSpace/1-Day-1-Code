#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};
int length = 0;
void insert(Node **head, int x);
int nthNodeFromLast1(Node *head, int n);
int nthNodeFromLast2(Node *head, int n);
int main(int argc, char const *argv[])
{
    // create linked 20->4->15->35
    Node *head = NULL;
    insert(&head, 20);
    insert(&head, 4);
    insert(&head, 15);
    insert(&head, 35);
 
    cout<<nthNodeFromLast2(head, 3);
    return 0;
}

/*
    Time complexity: O(n)
    Space complexity: O(1)

    Using two pointers
*/
int nthNodeFromLast2(Node* head, int n){

    if(head == NULL)return -1;
    Node* first = head;
    Node* second = head;

    int i=0;
    while(i<n){
        if(second == NULL)return -1;
        second = second->next;
        i++;
    }
    if(second == NULL){
        if(first)return first->data;
        else return -1;
    }

    while(second){
        first = first->next;
        second = second->next;
    }
    return first->data;
}

/*
    Time complexity: O(n)
    Space complexity: O(1)

    Using length of list
*/
int nthNodeFromLast1(Node *head, int n){

    if(length < n)return -1;
    int l = length - n + 1;
    int i=1;
    Node* temp = head;
    while(i<l){
        temp = temp->next;
        i++;
    }
    return temp->data;
}
void insert(Node **head, int x){
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    length++;
    if(*head == NULL){
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = newNode;

}