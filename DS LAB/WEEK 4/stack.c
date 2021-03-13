#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    struct node* next;
};
struct node* top = NULL;

void push(int value);
void pop();
void print_stack();
int search(int data);

int main(){
    int choice, data, idx;
    FILE *fptr;
    fptr = fopen("input.txt", "r");
    while (!feof(fptr))
    {       
        fscanf(fptr, "%d", &data);    
        push(data);  
    }
    fclose(fptr);
    do{
        printf("\n\n ==========Choose an operation on stack======== \n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                    printf("\nEnter value to push on stack: ");
                    scanf("%d", &data);
                    push(data);

                    break;
            case 2: pop();
                    break;
            case 3: 
                    printf("\nEnter value to search in stack: ");
                    scanf("%d", &data);
                    idx = search(data);
                    if(idx==-1)printf("\nElement %d not found in stack", data);
                    else printf("\nElement %d found at position %d in stack", data, idx);
                    break;
            case 4: print_stack();
                    break;
            default:
                    break;
        }
    }while(choice>=1 && choice<=4);
    return 0;
}

void push(int value){
    struct node* newNode = (struct node* )malloc(sizeof(struct node));
    newNode->next = NULL;
    newNode->data = value;

    if(top == NULL){
        top = newNode;
    }else{
        newNode->next = top;
        top = newNode;
    }
    return;
}

void pop(){
    if(top == NULL){
        printf("\n Stack is already empty");        //Underflow condition
    }else{
        struct node* temp = top;
        printf("%d popped out of stack\n", temp->data);
        top = top->next;
        free(temp);
    }
    return;
}
void print_stack(){
    struct node* head = top;
    if(head == NULL){
        printf("\nStack is empty\n");   
        return;
    }
    FILE *fptr = fopen("output.txt", "w");
    printf("\nStack :: top-> ");
    while(head!=NULL){
        printf(" %d |", head->data);
        fprintf(fptr, "%d ", head->data);
        head = head->next;
    }
    fclose(fptr);
    printf("\n");
    return;
}

int search(int data){
    struct node* head = top;
    if(head == NULL){
        printf("Stack is empty\n");
        return -1;
    }
    int idx = 0;
    while(head){
        if(head->data == data)return idx;
        idx++;
        head = head->next;
    }
    return -1;
}