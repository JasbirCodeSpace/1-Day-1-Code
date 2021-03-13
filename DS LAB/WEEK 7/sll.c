#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};
struct Node* head = NULL;
FILE *fptr = NULL;

void insert_node(int data);
void delete_node(int data);
void print_list();
void search_in_list(int data);
int main(){
    int choice, data, idx;
    fptr = fopen("input.txt", "r");
    while (!feof(fptr))
    {       
        fscanf(fptr, "%d", &data);    
        insert_node(data);  
    }
    fclose(fptr);
    do{
        printf("\n\n ==========Choose an operation on SLL======== \n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Print\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                    printf("\nEnter value to insert in list: ");
                    scanf("%d", &data);
                    insert_node(data);
                    break;
            case 2: printf("\nEnter value to delete in list: ");
                    scanf("%d", &data);
                    delete_node(data);
                    break;
            case 3: 
                    printf("\nEnter value to search in list: ");
                    scanf("%d", &data);
                    search_in_list(data);
                    break;
            case 4: print_list();
                    break;
            default:
                    break;
        }
    }while(choice>=1 && choice<=4);
    return 0;
}

void insert_node(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
    }else{
        
        if(data < head->data){
            newNode->next = head;
            head = newNode;
            return;
        }
        struct Node* curr = head;
        while(curr->next!=NULL && curr->next->data < data){
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
    return;
}

void delete_node(int data){
    struct Node* temp = NULL;
    if(head == NULL){
        return;
    }
    if(head->data == data){
        temp = head;
        head = head->next;
        free(temp);
        return;
    }
    struct Node* curr = head;
    while(curr->next!=NULL && curr->next->data != data){
        curr = curr->next;
    }
    if(curr->next != NULL){
        temp = curr->next;
        curr->next = curr->next->next;
        free(temp);
    }

    return;
}

void search_in_list(int data){
    int idx = 0;
    struct Node* curr = head;
    while(curr != NULL){
        if(curr->data == data){
            printf("\n %d found at position %d", data, idx);
            return;
        }
        curr = curr->next;
        idx++;
    }
    printf("\n%d not found in given linked list", data);
    return;
}

void print_list(){
    struct Node* curr = head;
    fptr = fopen("output.txt", "w");
    printf("\n head->");
    while(curr != NULL){
        printf(" %d ", curr->data);
        fprintf(fptr, "%d ", curr->data);
        if(curr->next)printf("->");
        curr = curr->next;
    }
    fclose(fptr);
    return;
}