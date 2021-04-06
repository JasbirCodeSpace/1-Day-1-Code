#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

class LinkedList{
    public:
    Node *head, *tail;

    public:
    LinkedList(){
        head = tail = NULL;
    }

    void push(int x){
        Node *newNode = new Node();
        newNode->data = x;
        newNode->next = NULL;

        if(head == NULL){
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    /*
        Time complexity: O(n)
        Space complexity: O(n)
    */
    bool detectLoop1(){
        unordered_set<Node*> s;
        Node *temp = head;

        while(temp){
            if(s.find(temp) != s.end())return true;
            s.insert(temp);
            temp = temp->next;
        }
        return false;
    }

    /*
        Time complexity: O(n)
        Space complexity: O(1)
    */
    bool detectLoop2(){

        Node *slowPtr = head, *fastPtr = head;
        while(fastPtr && fastPtr->next){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;

            if(slowPtr == fastPtr)return true;
        }
        return false;
    }

};

int main(int argc, char const *argv[])
{

    LinkedList ll;
 
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(10);
 
    /* Create a loop for testing */
    ll.head->next->next->next->next = ll.head;
 
    if (ll.detectLoop2())
        cout << "Loop found";
    else
        cout << "No Loop";    
    return 0;
}
