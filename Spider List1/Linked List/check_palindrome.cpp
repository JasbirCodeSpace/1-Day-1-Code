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
    /*
        Time complexity: O(n)
        Space complexity: O(n)
    */
    bool checkPalindrome1(){
        stack<int> s;
        Node *temp = head;

        while(temp){
            s.push(temp->data);
            temp = temp->next;
        }

        temp = head;
        while(!s.empty()){
            if(s.top() == temp->data){
                s.pop();
                temp = temp->next;
            }else{
                return false;
            }
        }
        return true;
    }

    /*
        Time complexity: O(n)
        Space complexity: O(1)
    */
    bool checkPalindrome2(){

        if(head == NULL || head->next == NULL)return true;

        Node *slowPtr  = head, *fastPtr = head;
        Node *middle = NULL, *prevSlowPtr = NULL, *secondHalf = NULL;

        while(fastPtr && fastPtr->next){
            prevSlowPtr = slowPtr;
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }

        if(fastPtr != NULL){        // odd length linked list
            middle = slowPtr;
            slowPtr = slowPtr->next;
        }

        secondHalf = slowPtr;
        prevSlowPtr->next = NULL;
        reverse(&secondHalf);
        bool result = compareList(head, secondHalf);
        reverse(&secondHalf);

        if(middle != NULL){
            prevSlowPtr->next = middle;
            middle->next = secondHalf;
        }else{
            prevSlowPtr->next = secondHalf;
        }
        return result;

    }
    void reverse(Node **node){

        Node *prev = NULL,*next = NULL;
        Node *curr = *node;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        *node = prev;
    }

    bool compareList(Node* head1, Node* head2){

        Node* temp1 = head1;
        Node* temp2 = head2;

        while (temp1 && temp2)
        {
            if(temp1->data != temp2->data)return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        if(temp1 == NULL && temp2 == NULL)return true;
        return false;
        
    }
};

int main(int argc, char const *argv[])
{
    LinkedList ll;
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    ll.insert(2);
    ll.insert(1);
        
    bool result = ll.checkPalindrome2();
   
    if(result)
            cout<<"Given linked list is palindrome\n";
    else
        cout<<"Given linked list is not palindrome\n";
    return 0;
}
