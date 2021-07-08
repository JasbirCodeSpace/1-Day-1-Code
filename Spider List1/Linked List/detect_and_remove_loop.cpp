#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node():data(-1),next(NULL){};
    Node(int x):data(x), next(NULL){};
};

class LinkedList{
    public:
    Node* head;
    Node* tail;
    public:
    LinkedList():head(NULL), tail(NULL){};
    void insert(int x){

        Node* newNode = new Node(x);
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
    /*
        Time complexity: O(n)
        Space complexity: O(1) 
    */
    void detectAndRemoveLoop1(){
        Node *slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                break;
        }
        
        if(slow == fast){
            int i=1;
            while(slow->next != fast){
                slow = slow->next;
                i++;
            }
            removeLoop(i);
        }
    }

    void removeLoop(int i){
        Node *ptr1 = head, *ptr2 = head;
        while(i>0){
            ptr2 = ptr2->next;
            i--;
        }
        if(ptr1 == ptr2){
            while(ptr2->next != ptr1)
                ptr2 = ptr2->next;
        }else{

            while(ptr1->next != ptr2->next){
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
        }
        ptr2->next = NULL;
    }

    /*
        Time complexity: O(n)
        Space complexity: O(n) 
    */
    void detectAndRemoveLoop2(){
        unordered_set<Node*> s;
        Node* curr = head;
        Node* last = NULL;
        while(curr){
            if(s.find(curr) != s.end()){
                last->next = NULL;
                return;
            }else{
                s.insert(curr);
                last = curr;
                curr = curr->next;
            }
            
        }
    }

};

int main(int argc, char const *argv[])
{
    LinkedList ll;
    ll.insert(20);
    ll.insert(4);
    ll.insert(15);
    ll.insert(10);
 
    /* Create a loop for testing */
    ll.head->next->next->next->next = ll.head;
    ll.detectAndRemoveLoop1();
    ll.printList();
    return 0;
}
