#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

class LinkedList{
    private:
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
        Space complexity: O(1)
    */
    void printMiddle1(){

        int length = 0;
        Node *temp = head;
        while(temp){
            length++;
            temp = temp->next;
        }

        for (int i = 0; i <= (length-1)/2; i++)
        {
            if(i==0)temp = head;
            else temp = temp->next;
        }

        if(temp)cout<<"Middle element is :: "<<temp->data<<'\n';
    }

    /*
        Time complexity: O(n)
        Space complexity: O(1)
    */
    void printMiddle2(){

        Node *slowPtr = head, *fastPtr = head;
        Node *prevSlowPtr = NULL;
        while(fastPtr && fastPtr->next){
            prevSlowPtr = slowPtr;
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }

        if(fastPtr == NULL){    // if even length
            slowPtr = prevSlowPtr;
        }

        if(slowPtr)cout<<"Middle element is :: "<<slowPtr->data<<'\n';
    }

    /*
        Time complexity: O(n)
        Space complexity: O(1)
    */
    void printMiddle3(){
        Node *curr = head, *prev = NULL;
        Node *mid = head;
        int count = 0;

        while(curr){
            if(count&1){
                prev = mid;
                mid = mid->next;
            }
            count++;
            curr = curr->next;
            
        }
       
        if((count&1) == 0)mid = prev;
        if(mid)cout<<"Middle element is :: "<<mid->data<<'\n';
    }
};

int main(int argc, char const *argv[])
{
    LinkedList ll;
    for (int i = 1; i <=5; i++)ll.push(i);
    ll.printMiddle3();
    return 0;
}
