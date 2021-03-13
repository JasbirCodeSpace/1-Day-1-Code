#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* root = NULL;
FILE *fptr = NULL;

// BST functions
struct Node* newNode(int key);
struct Node* inorderSuccessor(struct Node* node);
struct Node* insertNode(struct Node* node, int key);
struct Node* deleteNode(struct Node* node, int key);
struct Node* searchNode(struct Node* node, int key);
void preorder(struct Node* node);
void inorder(struct Node* node);
void postorder(struct Node* node);

// File functions
void readFromFile();
void writeToFile();
void writeToFile_export(struct Node* node, FILE* fptr);

int main(){
    int choice;
    int data;
    readFromFile();
    do
    {
        printf("\n\n ==========Choose an operation on BST======== \n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Search\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: 
                    printf("\nEnter value to insert in BST: ");
                    scanf("%d", &data);
                    root = insertNode(root, data);
                    break;
            case 2:
                    printf("\nEnter value to delete in BST: ");
                    scanf("%d", &data);
                    root = deleteNode(root, data);
                    break;
            case 3:
                    printf("\nEnter value to search in BST: ");
                    scanf("%d", &data);
                    searchNode(root, data);
                    break;
            case 4:
                    printf("\nInorder Traversal of BST: ");
                    inorder(root);
                    break; 
            case 5:
                    printf("\nPreorder Traversal of BST: ");
                    preorder(root);
                    break;
            case 6:
                    printf("\nPostorder Traversal of BST: ");
                    postorder(root);
                    break;                    
            default:
                    exit(0);
                    break;
        }
        printf("\n");
        writeToFile();

    } while (choice>=1 && choice<=6);
    
    return 0;
}

struct Node* newNode(int key){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->left = node->right = NULL;
    node->data = key;
    return node;
}

struct Node* insertNode(struct Node* node, int key){
    if(node == NULL)
        return newNode(key);
    if(key < node->data)
        node->left = insertNode(node->left, key);
    else if(key > node->data)
        node->right = insertNode(node->right, key);
    else
        printf("Duplicate key: %d", key);
    return node;
}

struct Node* inorderSuccessor(struct Node* node){
    struct Node* curr = node->right;
    while(curr && curr->left){
        curr = curr->left;
    }
    return curr;
}
struct Node* deleteNode(struct Node* node, int key){
    if(node == NULL)
        return node;
    if(key < node->data)
        node->left = deleteNode(node->left, key);
    else if(key > node->data)
        node->right = deleteNode(node->right, key);
    else{
        struct Node* temp ;
        if(node->left == NULL){
            temp = node->right;
            free(node);
            return temp;
        }
        else if(node->right == NULL){
            temp = node->left;
            free(node);
            return temp;
        }
        temp = inorderSuccessor(node);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }
    return node;
}

struct Node* searchNode(struct Node* node, int key){
    if(node == NULL){
        printf("%d is not present in given BST", key);
        return node;
    }
    if(node->data == key){
        printf("%d is present in given BST", key);
        return node;
    }else if(node->data > key){
        searchNode(node->left, key);
    }else{
        searchNode(node->right, key);
    }
}
void inorder(struct Node* node){
    if(node == NULL)
        return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

void preorder(struct Node* node){
    if(node == NULL)
        return;
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

void postorder(struct Node* node){
    if(node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}

void readFromFile(){
    int data;
    fptr = fopen("input.txt", "r");
    while (!feof(fptr))
    {       
        fscanf(fptr, "%d", &data);    
        root = insertNode(root, data);  
    }
    fclose(fptr);
}

void writeToFile(){
    fptr = fopen("output.txt", "w");
    writeToFile_export(root, fptr);
    fclose(fptr);
}

void writeToFile_export(struct Node* node, FILE* fptr){
    if(node == NULL)
        return;
    writeToFile_export(node->left, fptr);
    fprintf(fptr, "%d ", node->data);
    writeToFile_export(node->right, fptr);
}