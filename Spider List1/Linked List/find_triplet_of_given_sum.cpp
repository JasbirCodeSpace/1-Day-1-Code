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
    Time complexity: O(N^3)
    Space complexity: O(1)
*/
bool findTripletOfGivenSum1(Node *headA, Node *headB, Node *headC, int sum);
/*
    Sorting required
    Second list must be in increasing order and third list must be decreasing order
    Time complexity: O(N^2)
    Space complexity: O(1)
*/
bool findTripletOfGivenSum2(Node *headA, Node *headB, Node *headC, int sum);

int main(int argc, char const *argv[])
{
    Node* headA = NULL; 
    Node* headB = NULL; 
    Node* headC = NULL; 
  
    insert(&headA, 20); 
    insert(&headA, 4); 
    insert(&headA, 15); 
    insert(&headA, 10); 
  
    insert(&headB, 10); 
    insert(&headB, 9); 
    insert(&headB, 4); 
    insert(&headB, 2); 

    insert(&headC, 1); 
    insert(&headC, 2); 
    insert(&headC, 4); 
    insert(&headC, 8); 
  
    int sum = 25; 
  
    findTripletOfGivenSum2(headA, headB, headC, sum); 
    return 0;
}

bool findTripletOfGivenSum1(Node *headA, Node *headB, Node *headC, int sum){

    Node* a = headA;
    while(a){
        Node* b = headB;
        while(b){
            Node* c = headC;
            while(c){
                int res = a->data + b->data + c->data;
                if(res == sum){
                cout<<"Triplet: "<<a->data<<", "<<b->data<<", "<<c->data<<endl;
                return true;
                }
                c = c->next;
            }
            b = b->next;
        }

        a = a->next;
    }
    cout<<"No possible triplet found"<<endl;
    return false;
}
bool findTripletOfGivenSum2(Node *headA, Node *headB, Node *headC, int sum){
    // list b is sorted in ascending order
    // list c is sorted in descending order
    Node *a = headA;
    while(a){
        Node *b = headB, *c = headC;
        while(b && c){
            int res = a->data + b->data + c->data;
            if( res == sum){
                cout<<"Triplet: "<<a->data<<", "<<b->data<<", "<<c->data<<endl;
                return true;
            }
            else if(res < sum) b = b->next;
            else c = c->next;
        }
        a = a->next;
    }

    cout<<"No possible triplet found"<<endl;
    return false;
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
