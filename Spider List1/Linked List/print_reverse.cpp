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
        head = NULL;
        tail = NULL;
    }

    void insert(int x){
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = NULL;

        if(head == NULL){
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = tail->next;
    }

    void printReverse(){
       printReverseUtil(head); 
    }

    /*
        Time complexity: O(n)
        Space complexity: O(n)
    */
    void printReverseUtil(Node* node){
        if(node == NULL)return;

        printReverseUtil(node->next);
        cout<<node->data<<" ";
    }

};

int main(int argc, char const *argv[])
{
    LinkedList ll;
    ll.insert(4);
    ll.insert(3);
    ll.insert(2);
    ll.insert(1);
    ll.printReverse();
    return 0;
}
