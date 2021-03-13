#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    struct node* next;
};
struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int value);
void dequeue();
void print_queue();
int search(int data);

int main(){
    int choice, data, idx;
    FILE *fptr;
    fptr = fopen("input.txt", "r");
    while (!feof(fptr))
    {       
        fscanf(fptr, "%d", &data);    
        enqueue(data);  
    }
    fclose(fptr);
    do{
        printf("\n\n ==========Choose an operation on queue======== \n");
        printf("1. Enqueue \n");
        printf("2. Dequeue \n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                    printf("\nEnter value to insert in queue: ");
                    scanf("%d", &data);
                    enqueue(data);

                    break;
            case 2: dequeue();
                    break;
            case 3: 
                    printf("\nEnter value to search in queue: ");
                    scanf("%d", &data);
                    idx = search(data);
                    if(idx==-1)printf("\nElement %d not found in queue", data);
                    else printf("\nElement %d found at position %d in queue", data, idx+1);
                    break;
            case 4: print_queue();
                    break;
            default:
                    break;
        }
    }while(choice>=1 && choice<=4);
    return 0;
}

void enqueue(int value){
    struct node* newNode = (struct node* )malloc(sizeof(struct node));
    newNode->next = NULL;
    newNode->data = value;

    if(front == NULL){
        front = rear = newNode;
    }else{
        rear->next = newNode;
        rear = rear->next;
    }
    return;
}

void dequeue(){
    if(front == NULL){
        printf("\n Queue is already empty");        //Underflow condition
    }else{
        struct node* temp = front;
        printf("%d dequeued from the queue\n", temp->data);
        front = front->next;
        free(temp);
        if(front==NULL)
            rear = NULL;
    }

    return;
}
void print_queue(){
    FILE *fptr = fopen("output.txt", "w");
    struct node* head = front;
    if(head == NULL){
        printf("\nQueue is empty\n"); 
        fprintf(fptr, "");
        fclose(fptr);  
        return;
    }
    printf("\nQueue :: FRONT-> ");
    while(head!=NULL){
        printf(" %d |", head->data);
        fprintf(fptr, "%d ", head->data);
        head = head->next;
    }
    fclose(fptr);
    printf(" <-REAR\n");
    return;
}

int search(int data){
    struct node* head = front;
    if(head == NULL){
        printf("Queue is empty\n");
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