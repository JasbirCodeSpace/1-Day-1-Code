#include<bits/stdc++.h>
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
    }

    void swapOddEven1(){
        
        stack<Node*> odd;
        stack<Node*> even;
        Node *curr = head;
        int i=1;
        while(curr){
            if(curr->data%2 == 0 && i%2!=0){
                even.push(curr);
            }
            else if(curr->data%2 != 0 && i%2==0){
                odd.push(curr);
            }
            curr = curr->next;
            i++;
        }

        while(!odd.empty() && !even.empty()){
            swap(odd.top()->data, even.top()->data);
            odd.pop();
            even.pop();
        }
    }

    void swapOddEven2(){
        Node *os = NULL, *oe = NULL;
        Node *es = NULL, *ee = NULL;

        Node* curr = head;
        while(curr){
            if(curr->data & 1){
                if(os == NULL)
                    os = oe = curr;
                else{
                    oe->next = curr;
                    oe = oe->next;
                }
            }else{
                if(es == NULL){
                    es = ee = curr;
                }else{
                    ee->next = curr;
                    ee = ee->next;
                }
            }
            curr = curr->next;
        }

        Node* first, *second;

        if(head->data&1){
            first = os;
            second = es;
        }else{
            first = es;
            second = os;
        }

        Node* res= first;
        Node *t1, *t2, *ptr;
        while(first && second){
            t1 = first->next;
            t2 = second->next;

            first->next = second;
            second->next = t1;

            ptr = second;

            first = t1;
            second = t2;
        }

        if(first==NULL){
            first->next = second;
        }

        head = res;
    }

};

int main(int argc, char const *argv[])
{
    LinkedList ll;
    
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    ll.insert(5);
    ll.insert(6);
    ll.insert(7);
    ll.insert(8);

    ll.printList();

    cout<<"After odd even swap: "<<endl;
    ll.swapOddEven2();
    ll.printList();

    return 0;
}