#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void insert(Node** head, int x);
void printList(Node* head);
bool isNodePresent(Node* head, int x);

/*
    Time complexity: O(m*n)
    Space complexity: O(1)
*/
Node* getUnion1(Node* head1, Node* head2);
Node* getIntersection1(Node* head1, Node* head2);

/*
    Time complexity: O(m+n)
    Space complexity: O(m+n)
*/
Node* getUnion2(Node* head1, Node* head2);
Node* getIntersection2(Node* head1, Node* head2);
int main(int argc, char const *argv[])
{
    Node* a = NULL;
    Node* b = NULL;
    Node* intersectList = NULL;
    Node* unionList = NULL;
    
    insert(&a, 6);
    insert(&a, 5);
    insert(&a, 4);
    insert(&a, 3);
    insert(&a, 2);
    insert(&a, 1);
    printList(a);
 
    insert(&b, 8);
    insert(&b, 6);
    insert(&b, 4);
    insert(&b, 2);
    printList(b); 

    intersectList = getIntersection2(a, b);
    unionList = getUnion2(a, b);
    cout << "\nIntersection list is\n ";
    printList(intersectList);
    cout << "\nUnion list is\n";
    printList(unionList);
    return 0;
}

Node* getIntersection1(Node* head1, Node* head2){

    Node *head = NULL;

    Node* curr = head1;
    while(curr){
        if(isNodePresent(head2, curr->data))
            insert(&head, curr->data);
        curr = curr->next;
    }
    return head;
}

Node* getUnion1(Node* head1, Node* head2){

    Node* curr = head1;
    Node *head=NULL;
    while(curr){
        insert(&head, curr->data);
        curr = curr->next;
    }

    curr = head2;
    while(curr){
        if(!isNodePresent(head, curr->data))
            insert(&head, curr->data);
        curr = curr->next;
    }

    return head;
}

Node* getUnion2(Node* head1, Node* head2){
    unordered_set<int> s;
    Node* head = NULL;
    while(head1){
        s.insert(head1->data);
        head1 = head1->next;
    }
    while(head2){
        s.insert(head2->data);
        head2 = head2->next;
    }

    for (auto i = s.begin(); i != s.end(); i++)
        insert(&head, *i);
    
    return head;
    
}

Node* getIntersection2(Node* head1, Node* head2){

    unordered_set<int> s;
    Node* head = NULL;

    while(head1){
        s.insert(head1->data);
        head1 = head1->next;
    }
    while(head2){
        if(s.find(head2->data) != s.end())
            insert(&head, head2->data);
        head2 = head2->next;
    }

    return head;
}
void insert(Node** head, int x){
    Node *newNode = new Node();
    newNode->data = x;
    newNode->next = *head;
    *head = newNode;

}

bool isNodePresent(Node* head, int x){
    while(head){
        if(head->data == x)return true;
        head = head->next;
    }
    return false;
}
void printList(Node* head){

    while(head){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<'\n';
}