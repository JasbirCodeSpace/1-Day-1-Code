#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    char data;
    Node* next;
};

void insert(Node** head, char x);
void printList(Node* head);
bool isVowel(char c);
/*
    Time complexity: O(N)
    Space complexity: O(1)
*/
void moveVowelsToEnd(Node **head);
int main(int argc, char const *argv[])
{
    Node *head = NULL;
    insert(&head, 'i');
    insert(&head, 'x');
    insert(&head, 'o');
    insert(&head, 'd');
    insert(&head, 'e');
    insert(&head, 'c');
    insert(&head, 'b');
    insert(&head, 'a');
    printf("Linked list before :\n");
    printList(head);
    
    moveVowelsToEnd(&head);
 
    printf("Linked list after :\n");
    printList(head);
    return 0;
}
void moveVowelsToEnd(Node **head){

    Node *vowel_s = NULL, *vowel_e = NULL;
    Node *cons_s = NULL, *cons_e = NULL;
    Node* curr = *head;
    while(curr){
        if(isVowel(curr->data)){
            if(vowel_s == NULL){
                vowel_s = vowel_e = curr;
            }else{
                vowel_e->next = curr;
                vowel_e = vowel_e->next;
            }
        }else{
            if(cons_s == NULL){
                cons_s = cons_e = curr;
            }else{
                cons_e->next = curr;
                cons_e = cons_e->next;
            }
        }
        curr = curr->next;
    }

    if(vowel_s == NULL || cons_s == NULL)return;
    vowel_e->next = cons_s;
    cons_e->next = NULL;
    *head = vowel_s;

}
void insert(Node** head, char x){
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = *head;
    *head = newNode;
}

void printList(Node* head){

    while(head){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

bool isVowel(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    return false;
}