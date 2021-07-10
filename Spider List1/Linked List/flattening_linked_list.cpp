#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* right;
    Node* down;
    Node():data(0), right(NULL), down(NULL){};
    Node(int x): data(x), right(NULL), down(NULL){};
};

class LinkedList{
    public:
    Node* head;

    public:
    LinkedList():head(NULL){};

    Node* push(Node* head_ref, int data){
        Node* newNode = new Node(data);
        newNode->down = head_ref;
        head_ref = newNode;
        return head_ref;
    }

    void printList(){
        Node* curr = head;
        while(curr){
            cout<<curr->data<<" -> ";
            curr = curr->down;
        }
        cout<<endl;
    }

    Node* merge(Node* a, Node* b){
        if(a == NULL)
            return b;
        if(b == NULL)
            return a;
        
        Node* result;
        if(a->data <= b->data){
            result = a;
            result->down = merge(a->down, b);
        }else{
            result = b;
            result->down = merge(a, b->down);
        }
        result->right = NULL;
        return result;
    }
    Node* flatten(Node* head){
        if(head == NULL || head->right == NULL)
            return head;
        
        head->right = flatten(head->right);
        head = merge(head, head->right);
        return head;
    }
};


int main(int argc, char const *argv[])
{
    LinkedList L;
  
        /* Let us create the following linked list
            5 -> 10 -> 19 -> 28
            |    |     |     |
            V    V     V     V
            7    20    22    35
            |          |     |
            V          V     V
            8          50    40
            |                |
            V                V
            30               45
        */
  
        L.head = L.push(L.head, 30);
        L.head = L.push(L.head, 8);
        L.head = L.push(L.head, 7);
        L.head = L.push(L.head, 5);
  
        L.head->right = L.push(L.head->right, 20);
        L.head->right = L.push(L.head->right, 10);
  
        L.head->right->right = L.push(L.head->right->right, 50);
        L.head->right->right = L.push(L.head->right->right, 22);
        L.head->right->right = L.push(L.head->right->right, 19);
  
        L.head->right->right->right = L.push(L.head->right->right->right, 45);
        L.head->right->right->right = L.push(L.head->right->right->right, 40);
        L.head->right->right->right = L.push(L.head->right->right->right, 35);
        L.head->right->right->right = L.push(L.head->right->right->right, 20);
  
        // flatten the list
        L.head = L.flatten(L.head);
  
        L.printList();
    return 0;
}
