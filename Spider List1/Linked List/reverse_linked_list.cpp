#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

class LinkedList{
    private:
        Node* head;
    public:
        LinkedList(){
            head = NULL;
        }
        void insert(int x){

            Node* newNode = new Node();
            newNode->next = NULL;
            newNode->data = x;

            if(head == NULL){
                head = newNode;
                return;
            }

            Node* temp = head;
            while(temp->next){
                temp = temp->next;
            }
            temp->next = newNode;
            return;
        }

        /*
            Time complexity: O(n)
            Space complexity: O(1)
        */
        void reverse1(){
            Node* curr = head;
            Node* prev = NULL;
            Node* next = NULL;

            while (curr)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            head = prev;
            
        }
        /*
            Time complexity: O(n)
            Space complexity: O(n)
        */
        void reverse2(){
            reverse2Util(head);
        }

        Node* reverse2Util(Node* node){
            if(node == NULL || node->next == NULL){
                head = node;
                return node;
            }

            Node* temp = reverse2Util(node->next);
            temp->next = node;
            node->next = NULL;
            return node;
        }
        /*
            Time complexity: O(n)
            Space complexity: O(n)
        */
        void reverse3(){
            stack<Node* > s;

            Node* temp = head;
            while(temp->next){
                s.push(temp);
                temp= temp->next;
            }

            head = temp;
            while(!s.empty()){
                temp->next = s.top();
                s.pop();
                temp = temp->next;
            }
            temp->next = NULL;
        }
        void print(){
            Node* temp = head;
            while(temp){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }
};
int main(int argc, char const *argv[])
{
    /* Start with the empty list */
    LinkedList ll;
    ll.insert(20);
    ll.insert(4);
    ll.insert(15);
    ll.insert(85);
 
    cout << "Given linked list\n";
    ll.print();
 
    ll.reverse3();
 
    cout << "\nReversed Linked list \n";
    ll.print();  
    return 0;
}
