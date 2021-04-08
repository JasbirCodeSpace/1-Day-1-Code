#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void insert(Node** head, int x);
void printList(Node* head);
Node* sortedIntersection1(Node *head1,Node *head2);
Node* sortedIntersection2(Node* head1, Node* head2);
int main(int argc, char const *argv[])
{
    Node* a = NULL;
    Node* b = NULL;
    Node* intersect = NULL;
    
    insert(&a, 6);
    insert(&a, 5);
    insert(&a, 4);
    insert(&a, 3);
    insert(&a, 2);
    insert(&a, 1);
    printList(a);
 
    insert(&b, 8);
    insert(&b, 6);
    insert(&b, 4);
    insert(&b, 2);
    printList(b);
 
    intersect = sortedIntersection2(a, b);
 
    cout<<"Linked list containing common items of a & b \n";
    printList(intersect);
    return 0;
}

/*
    Time complexity: O(M + N)
    Space complexity: O(min(M, N))
*/
Node* sortedIntersection1(Node *head1, Node *head2){
    Node* head = NULL;
    Node* tail;

    while(head1 && head2){
        if(head1->data == head2->data){
            Node* temp = new Node();
            temp->data = head1->data;
            temp->next = NULL;
            if(head == NULL){
                head = tail = temp;
            }else{
                tail->next = temp;
                tail = temp;
            }
            head1 = head1->next;
            head2 = head2->next;

        }else if(head1->data < head2->data){
            head1 = head1->next;
        }else{
             head2 = head2->next;
        }
    }
    return head;
}

/* 
    Time complexity: O(M+N)
    Space complexity: O(min(M, N))
*/
Node* sortedIntersection2(Node* head1, Node* head2){

    if(head1 == NULL || head2 == NULL)return NULL;

    if(head1->data < head2->data)
        return sortedIntersection2(head1->next, head2);
    if(head1->data > head2->data)
        return sortedIntersection2(head1, head2->next);
    
    Node* temp = new Node();
    temp->data = head1->data;
    temp->next = sortedIntersection2(head1->next, head2->next);
    return temp;

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