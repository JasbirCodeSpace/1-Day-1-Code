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
    LinkedList():head(NULL),tail(NULL){};

    void insert(int x){
        Node *newNode = new Node(x);
        if(head == NULL){
            head = tail = newNode;
        }else{
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

    int countNodes(){
        int count = 0;
        Node* curr = head;
        while(curr){
            curr = curr->next;
            count++;
        }
        return count;
    }
    
    /*
        Time complexity: O(N)
    */
    void swapKth(int k){

        int n = countNodes();
        if(n<k)
            return;
        if(2*k-1 == n)
            return;
        
        Node* a = head;
        Node* aPrev = NULL;
        for(int i=1; i<k; i++){
            aPrev = a;
            a = a->next;
        }

        Node* b = head;
        Node* bPrev = NULL;
        for(int i=1; i<n-k+1; i++){
            bPrev = b;
            b = b->next;
        }

        if(aPrev)
        aPrev->next = b;
        if(bPrev)
        bPrev->next = a;

        Node* temp = a->next;
        a->next = b->next;
        b->next = temp;

        if(k==1)
            head = b;
        if(k==n)
            head = a;

    }
};


int main(int argc, char const *argv[])
{
    LinkedList ll;
    Node* head = NULL;
    for (int i = 8; i >= 1; i--)
        ll.insert(i);
 
    cout << "Original Linked List: ";
    ll.printList();
 
    for (int k = 1; k < 9; k++) {
        ll.swapKth(k);
        cout << "\nModified List for k = " << k << endl;
        ll.printList();
    } 
    return 0;
}
