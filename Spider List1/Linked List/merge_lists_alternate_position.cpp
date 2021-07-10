#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node():data(-1), next(NULL){};
    Node(int x):data(x), next(NULL){};
};

class LinkedList{
    public:
    Node *head, *tail;
    
    public:
    LinkedList():head(NULL), tail(NULL){};
    void insert(int x){

        Node* newNode = new Node(x);
        if(head == NULL)
            head = tail = newNode;
        else{
            tail->next = newNode;
            tail = tail->next;
        }
    }

    void printList(){

            Node* curr = head;
            while(curr){
                cout<<curr->data<<" -> ";
                curr = curr->next;
            }
            cout<<endl;
    }

    // T(n) = O(N)
    void mergeAlternate(Node **head2){

        Node *a_curr = head, *a_next;
        Node *b_curr = *head2, *b_next;

        while(a_curr && b_curr){

            a_next = a_curr->next;
            b_next = b_curr->next;

            a_curr->next = b_curr;
            b_curr->next = a_next;

            a_curr = a_next;
            b_curr = b_next;
        }

        *head2 = b_curr;
    }
};

int main(int argc, char const *argv[])
{
    LinkedList p, q;
    p.insert(3);
    p.insert(2);
    p.insert(1);
    cout<<"First Linked List:\n";
   p. printList();
 
    q.insert(8);
    q.insert(7);
    q.insert(6);
    q.insert(5);
    q.insert(4);
    cout<<"Second Linked List:\n";
    q.printList();
 
    p.mergeAlternate(&q.head);
 
    cout<<"Modified First Linked List:\n";
    p.printList();
 
    cout<<"Modified First Linked List:\n";
    q.printList();
    return 0;
}
