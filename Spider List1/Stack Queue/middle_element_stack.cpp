#include<bits/stdc++.h>
using namespace std;

class DLLNode
{
public:
    DLLNode* prev;
    DLLNode* next;
    int data;
};

class Stack
{
private:
    DLLNode* head;
    DLLNode* middle;
    int size;
public:
    void push(int data){
        DLLNode* newNode = new DLLNode();
        newNode->prev = NULL;
        newNode->next = this->head;
        newNode->data = data;
        this->size += 1;

        if(this->size == 1){
            middle = newNode;

        }else{
            this->head->prev = newNode;
            if(!(this->size & 1)){
                middle = middle->prev;
            }
        }
        this->head = newNode;
        cout<<"Pushed: "<<data<<'\n';
    }

    int pop(){
        if(this->size == 0){
            cout<<"Stack is empty\n";
            return -1;
        }
        int item = this->head->data;
        DLLNode* temp = this->head;
        this->head = this->head->next;
        this->size -= 1;

        if(this->head != NULL)
            this->head->prev = NULL;

        if(this->size & 1){
            this->middle = this->middle->next;
        }
        delete(temp);
        cout<<"Popped: "<<item<<'\n';
        return item;

    }

    int getMiddle(){
        if(this->head == NULL){
            cout<<"Stack is empty\n";
            return -1;
        }
        int item = this->middle->data;
        cout<<"Middle element: "<<item<<'\n';
        return item;
    }

    void deleteMiddle(){
        if(this->head == NULL){
            cout<<"Stack is empty\n";
            return;
        }

        DLLNode* temp = this->middle;
        if(this->size & 1)
            this->middle = this->middle->prev;
        if(this->size !=1){

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        this->size -= 1;
        delete(temp);
    }
};

int main(int argc, char const *argv[])
{
    Stack* s = new Stack();
    s->push(11);
    s->push(22);
    s->push(33);
    s->push(44);
    s->push(55);
    s->push(66);
    s->push(77);
    s->pop();
    s->pop();
    s->getMiddle();
    return 0;
}
