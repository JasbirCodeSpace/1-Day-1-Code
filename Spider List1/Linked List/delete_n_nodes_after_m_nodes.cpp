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
    void skipMdeleteN(int m, int n){
        Node* curr = head;
        while(curr){
            for(int i=1; i<m && curr; i++){
                curr = curr->next;
            }
            if(curr == NULL)
                return;
            Node* t = curr->next;

            for(int i=1; i<=n && t; i++){
                Node* temp = t;
                t = t->next;
                free(temp);
            }
            curr->next = t;
            curr = t;
        }
    }
};

int main(int argc, char const *argv[])
{
    LinkedList ll;
    for(int i=1; i<=20; i++)
        ll.insert(i);
    ll.printList();
    cout<<"Deleting 3 nodes after 4 nodes: "<<endl;
    ll.skipMdeleteN(4, 3);
    ll.printList();
    return 0;
}
