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

    void insert(int x){
        Node *newNode = new Node();
        newNode->data = x;
        newNode->next = NULL;

        if(head == NULL){
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = tail->next;
    }

    void deleteLL(){
        Node *temp, *curr = head;

        while(curr){
            temp = curr;
            curr = curr->next;
            delete(temp);
        }

        head = NULL;
    }
};

int main(int argc, char const *argv[])
{
    LinkedList ll;
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);

    cout<<"Deleting linked list ...\n";
    ll.deleteLL();
    cout<<"Linked list deleted\n";
    return 0;
}
