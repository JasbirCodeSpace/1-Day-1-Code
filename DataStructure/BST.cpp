#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left, *right;
};

struct Node *new_node(int key)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

// Insertion in BST
struct Node *insert_node(struct Node *node, int key)
{
    if (node == NULL)
        return new_node(key);
    if (key < node->key)
    {
        node->left = insert_node(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert_node(node->right, key);
    }

    return node;
}

// Searching an element in BST
struct Node *search(struct Node *root, int key)
{
    if (root == NULL || root->key == key)
    {
        return root;
    }
    if (key < root->key)
    {
        search(root->left, key);
    }
    else if (key > root->key)
    {
        search(root->right, key);
    }
}
// Depth First Traversal Methods
void inorder(struct Node *node)
{
    if (node != NULL)
    {
        inorder(node->left);
        printf("%d ", node->key);
        inorder(node->right);
    }
}

void preorder(struct Node *node)
{
    if (node != NULL)
    {
        printf("%d ", node->key);
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder(struct Node *node)
{
    if (node != NULL)
    {
        preorder(node->left);
        preorder(node->right);
        printf("%d ", node->key);
    }
}

int main()
{
    /*creating following BST 
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 */
    struct Node *root = insert_node(NULL, 50);
    insert_node(root, 30);
    insert_node(root, 20);
    insert_node(root, 40);
    insert_node(root, 70);
    insert_node(root, 60);
    insert_node(root, 80);

    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\nPreorder Traversal: ");
    preorder(root);
    printf("\nPostorder Traversal: ");
    postorder(root);

    return 0;
}