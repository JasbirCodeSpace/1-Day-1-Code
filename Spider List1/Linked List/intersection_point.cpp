#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

int getLength(Node* head);
int getIntersectionNode1(Node* head1, Node* head2);
int getIntersectionNode2(Node* head1, Node* head2);
int getIntersectionNode3(Node* head1, Node* head2);


int main(int argc, char const *argv[])
{

    /* 
        Create two linked lists 
      
        1st 3->6->9->15->30 
        2nd 10->15->30 
      
        15 is the intersection point 
    */
  
    Node* newNode;
  
    // Addition of new nodes
    Node* head1 = new Node();
    head1->data = 10;
  
    Node* head2 = new Node();
    head2->data = 3;
  
    newNode = new Node();
    newNode->data = 6;
    head2->next = newNode;
  
    newNode = new Node();
    newNode->data = 9;
    head2->next->next = newNode;
  
    newNode = new Node();
    newNode->data = 15;
    head1->next = newNode;
    head2->next->next->next = newNode;
  
    newNode = new Node();
    newNode->data = 30;
    head1->next->next = newNode;
  
    head1->next->next->next = NULL;
  
    cout << "The node of intersection is " << getIntersectionNode3(head1, head2);
    return 0;
}

/*
    Time complexity: O(M*N)
    Space complexity: O(1)
*/
int getIntersectionNode1(Node* head1, Node* head2){

    Node* curr1 = head1;
    while(curr1){
        Node* curr2 = head2;
        while(curr2){
            if(curr1 == curr2)return curr1->data;
            curr2 = curr2->next;
        }
        curr1 = curr1->next;
    }
    return -1;
}

/*
    Time complexity: O(M + N)
    Space complexity: O(1)
*/
int getIntersectionNode2(Node* head1, Node* head2){

    int length1 = getLength(head1);
    int length2 = getLength(head2);

    int diff = abs(length1-length2);
    Node *curr1, *curr2;
    if(length1>length2){
        curr1 = head1;
        curr2 = head2;
    }else{
        curr1 = head2;
        curr2 = head1;
    }

    for (int i = 0; i < diff; i++)
    {
        curr1 = curr1->next;
    }

    while (curr1 && curr2)
    {
        if(curr1 == curr2)return curr1->data;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    return -1;
    
    

}

/* 
    Time complexity: O(M+N)
    Space complexity: O(1)
*/
int getIntersectionNode3(Node* head1, Node* head2){

    Node* curr1 = head1;
    Node* curr2 = head2;

    if(curr1 == NULL || curr2 == NULL)return -1;

    while(curr1 != curr2){
        curr1 = curr1->next;
        curr2 = curr2->next;

        if(curr1 == curr2)return curr1->data;

        if(curr1 == NULL)curr1 = head2;
        if(curr2 == NULL)curr2 = head1;
    }

    return curr1->data;
}
int getLength(Node* head){
    Node* curr = head;
    int count = 0;
    while(curr){
        count++;
        curr = curr->next;
    }
    return count;
}