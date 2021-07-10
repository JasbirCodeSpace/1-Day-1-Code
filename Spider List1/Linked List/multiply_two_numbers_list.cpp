#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void insert(Node **head, int x);
void printList(Node *head);
/*
    Time Complexity: O(M+N)
    Space Complexity: O(1)
*/
double mulTwoList(Node *a, Node *b);

/*
    Time complexity: O(M*N)
*/
Node* multiplyTwoList(Node* a, Node* b);
int reverse(Node** head);
Node* makeEmptyList(int n);

int main(int argc, char const *argv[])
{
    Node *head1 = NULL, *head2 = NULL; 
   
    int arr1[] = {5, 6, 7}; 
    int arr2[] = {1, 8}; 
   
    int size1 = sizeof(arr1) / sizeof(arr1[0]); 
    int size2 = sizeof(arr2) / sizeof(arr2[0]); 
   
    int i; 
    for (i = size1-1; i >= 0; --i) 
        insert(&head1, arr1[i]); 
   
    for (i = size2-1; i >= 0; --i) 
        insert(&head2, arr2[i]); 
    
    printList(head1);
    printList(head2);
    double result=mulTwoList(head1, head2);
    cout<<"Product = "<<result<<endl; 

    Node* res = multiplyTwoList(head1, head2);
    printList(head1);
    printList(head2);
    printList(res);  
    return 0;
}

double mulTwoList(Node *a, Node *b){
    double x = 0, y = 0;
    while(a){
        x = x*10 + a->data;
        a = a->next;
    }
    while(b){
        y = y*10 + b->data;
        b = b->next;
    }
    return x*y;
}

int reverse(Node** head){
    Node *curr=*head, *prev = NULL, *next = NULL;
    int count = 0;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    *head = prev;
    return count;
}

Node* makeEmptyList(int n){

    Node* head = NULL;
    while(n--){
        Node* newNode = new Node;
        newNode->data = 0;
        newNode->next = NULL;
        newNode->next = head;
        head = newNode;
    }
    return head;
}

Node* multiplyTwoList(Node* a, Node* b){
    int m = reverse(&a);
    int n = reverse(&b);
    Node* result = makeEmptyList(m+n+1);
    Node *first = NULL, *second = b, *result1 = result, *result2 = NULL;


    while(second){
        int carry = 0;
        result2 = result1;
        first = a;
        while(first){
            int mul = first->data * second->data + carry;
            result2->data += mul%10;
            carry = mul/10 + result2->data/10;
            result2->data = result2->data%10;
        
            first = first->next;
            result2 = result2->next;
        }
        if(carry){
            result2->data += carry;
        }
        result1 = result1->next;
        second = second->next;
    }

    reverse(&result);
    reverse(&a);
    reverse(&b);
    while(result->data == 0){
        Node *temp = result;
        result = result->next;
        free(temp);
    }
    return result;
}
void insert(Node **head, int x){
    Node *newNode = new Node();
    newNode->data = x;
    newNode->next = *head;
    *head = newNode;
}

void printList(Node *head){
    while(head){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}