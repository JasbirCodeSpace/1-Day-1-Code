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

        /*
            Time complexity: O(N*logN)
            Space complexity; O(logn)
        */
        void mergeSort(){
            head = mergeSortUtil(head);    
        }

        Node* mergeSortUtil(Node* head){
            if(head == NULL || head->next == NULL)
                return head;
            Node* mid = findMid(head);
            Node *head1 = head , *head2 = mid->next;
            mid->next = NULL;
            Node* h1 = mergeSortUtil(head1);
            Node* h2 = mergeSortUtil(head2);
            Node* res = merge(h1, h2);
            return res;
        }

        Node* findMid(Node* head){
            Node *slow = head, *fast = head->next;
            while(fast && fast->next){
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }

        Node* merge(Node* head1, Node* head2){
            Node* merged = new Node;
            Node* head = merged;

            while(head1 && head2){
                if(head1->data <= head2->data){
                    head->next = head1;
                    head1 = head1->next;
                }else{
                    head->next = head2;
                    head2 = head2->next;
                }
                head = head->next;
            }

            while(head1){
                head->next = head1;
                head = head->next;
                head1 = head1->next;
            }
            while(head2){
                head->next = head2;
                head = head->next;
                head2 = head2->next;
            }

            return merged->next;
        }
        

};

int main(int argc, char const *argv[])
{
    LinkedList ll;
    ll.insert(9);
    ll.insert(7);
    ll.insert(6);
    ll.insert(4);
    ll.insert(2);
    ll.insert(0);
    ll.printList();
    ll.mergeSort();
    ll.printList();
    return 0;
}
