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
        printf("\n\n ==========Choose an operation on CLL======== \n");
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
    if(head == NULL){
        newNode->next = newNode;
        head = newNode;

    }
    else if(head->next == head){
            newNode->next = head;
            head->next = newNode;
            if(head->data > data){

            }else{
 
                head = newNode;
            }
            return;
    }else{
        struct Node* curr = head->next;
        if(curr->data > data){
            head->next = newNode;
            newNode->next = curr;
        }else{

            while(curr->next != head->next && curr->next->data < data){
                curr = curr->next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
            if(curr->next == head->next && data >= curr->data){
                head = head->next;
            }
        }
    }

    return;
}

void delete_node(int data){
    if(head == NULL){
        return;
    }
    struct Node* curr = head->next;
    struct Node* temp = NULL;

    if(curr->data == data){
        temp = curr;
        if(curr->next == curr)head = NULL;
        else  head->next = head->next->next;
        free(temp);
        return;
    }

    while(curr->next!=head->next && curr->next->data != data){
        curr = curr->next;
    }
    if(curr->next != head->next){
        temp = curr->next;
        if(curr->next == head)
            head = curr;
        curr->next = curr->next->next;
        free(temp);
    }else{
        
    }


    return;
}

void search_in_list(int data){
    int idx = 0;
    struct Node* curr = head;
    if(curr != NULL){
        do{
            if(curr->data == data){
                printf("\n %d found at position %d", data, idx);
                return;
            }
            curr = curr->next;
            idx++;
        }while(curr != head);
    }
    printf("\n%d not found in given linked list", data);
    return;
}

void print_list(){
    fptr = fopen("output.txt", "w");
    if(head != NULL){
        struct Node* curr = head->next;
        printf("->");
        do{
            printf(" %d ", curr->data);
            fprintf(fptr, "%d ", curr->data);
            curr = curr->next;
            if(curr != head->next)printf("->");
        }while(curr != head->next);
        printf("<-head");
    }else{
        printf("NULL <-head");
        fprintf(fptr, "%s","NULL");
    }
    fclose(fptr);
    return;
}