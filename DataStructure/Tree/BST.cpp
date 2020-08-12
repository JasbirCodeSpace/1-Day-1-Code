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

// Get minimum value node in BST
struct Node *min_value_node(struct Node *root)
{
    struct Node *current = root;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Get maximum value node in BST
struct Node *max_value_node(struct Node *root)
{
    struct Node *current = root;
    while (current && current->right != NULL)
        current = current->right;
    return current;
}

// height of BST

int height(struct Node *root)
{
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
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

// Deletion in BST
struct Node *delete_node(struct Node *root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->key)
    {
        root->left = delete_node(root->left, key);
        return root;
    }
    else if (key > root->key)
    {
        root->right = delete_node(root->right, key);
        return root;
    }
    else
    {
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == NULL)
        {
            struct Node *temp = root->left;
            delete root;
            return temp;
        }

        Node *succParent = root;
        Node *succ = root->right;
        while (succ->left != NULL)
        {
            succParent = succ;
            succ = succParent->left;
        }
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
        root->key = succ->key;
        delete succ;
        return root;
    }
    return root;
}

// Searching an element in BST
struct Node *search_node(struct Node *root, int key)
{
    if (root == NULL || root->key == key)
    {
        return root;
    }
    if (key < root->key)
    {
        return search_node(root->left, key);
    }
    return search_node(root->right, key);
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

// Bredth First Traversal
void levelorder(struct Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    printf("\n");
    while (!q.empty())
    {
        Node *node = q.front();
        printf("%d ", node->key);
        q.pop();
        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
    }
    printf("\n");
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

    printf("\n\nHeight of BST: %d", height(root));

    printf("\n\n=======DFS Traversing=======");
    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\nPreorder Traversal: ");
    preorder(root);
    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\n\n=======BFS Traversing=======");
    levelorder(root);

    printf("\n\n=======Searching=======");
    int searchKey = 44;
    printf("\n%d in given BST: %s", searchKey, search_node(root, searchKey) == NULL ? "false" : "true");
    searchKey = 70;
    printf("\n%d in given BST: %s", searchKey, search_node(root, searchKey) == NULL ? "false" : "true");

    printf("\n\n=======Deletion=======");
    int deleteKey = 54;
    delete_node(root, deleteKey);
    printf("\nInorder of BST after deletion of %d\n", deleteKey);
    inorder(root);

    deleteKey = 50;
    delete_node(root, deleteKey);
    printf("\nInorder of BST after deletion of %d\n", deleteKey);
    inorder(root);

    return 0;
}