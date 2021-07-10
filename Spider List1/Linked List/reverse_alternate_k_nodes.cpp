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
    private:
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

    // T(n) = O(n)
    Node* reverseAlternateKNodes(int k){
        return _reverseAlternateKNodes(head, k, true);
    }

    Node* _reverseAlternateKNodes(Node* head, int k, bool b){
        if(head == NULL || head->next == NULL)
            return head;
        
        Node *prev = NULL, *curr = head, *next = NULL;
        int i=1;
        while(curr && i<=k){
            next = curr->next;
            if(b)
                curr->next = prev;
            prev = curr;
            curr = next;
            i++;
        }

        if(b){
            head->next = _reverseAlternateKNodes(curr, k, false);
            return prev;
        }
        else{
            prev->next = _reverseAlternateKNodes(curr, k, true);
            return head;
        }

    }
};

void printList(Node* head){

            Node* curr = head;
            while(curr){
                cout<<curr->data<<" -> ";
                curr = curr->next;
            }
            cout<<endl;
}

int main(int argc, char const *argv[])
{
    LinkedList ll;
    for(int i=1; i<=20; i++)
        ll.insert(i);
    ll.printList();
    cout<<"After 3 alternate reverse: "<<endl;
    Node* head = ll.reverseAlternateKNodes(3);
    printList(head);
    return 0;
}
