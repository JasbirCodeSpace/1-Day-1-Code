#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node* next;
};

Node* newNode(int x){
    Node* node = new Node();
    node->data = x;
    node->left = node->right = node->next = NULL;
    return node;
};


Node* nextRight(Node* root){
    Node* temp = root->next;
    while(temp){
            if(temp->left)
                return temp->left;
            else if(temp->right)
                return temp->right;
            temp = temp->next;
    }
    return NULL;
}
// T(n) = O(n)
void connectLevel1(Node* node){
    if(node == NULL)
        return;
    
    node->next = NULL;
    while(node){

        Node* temp = node;
        while(temp){

            if(temp->left){
                if(temp->right)
                    temp->left->next = temp->right;
                else
                    temp->left->next = nextRight(temp);
            }
            if(temp->right)
                temp->right->next = nextRight(temp);

            temp = temp->next;
        }
        if(node->left)
            node = node->left;
        else if(node->right)
            node = node->right;
        else
            node = nextRight(node);
    }
}

/*
    T(n) = O(n)
    Space = O(N)
*/
void connectLevel2(Node* node){
    if(node==NULL)
        return;
    
    queue<Node*> q;
    q.push(node);
    Node* prev = NULL;
    while(!q.empty()){
        int size = q.size();

        prev = NULL;

        while(size--){
            Node* temp = q.front();
            q.pop();

            if(prev)
                prev->next = temp;
            prev = temp;

            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }

}
int main(int argc, char const *argv[])
{
     /* Constructed binary tree is
            10
            / \
         8      2
        /        \
        3           90
    */
    Node *root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->right->right     = newNode(90);
 
    // Populates nextRight pointer in all nodes
    connectLevel2(root);
 
    // Let us check the values of nextRight pointers
    cout << "Following are populated nextRight pointers in the tree"
        " (-1 is printed if there is no nextRight) \n";
    cout << "nextRight of " << root->data << " is "
        << (root->next? root->next->data: -1) <<endl;
    cout << "nextRight of " << root->left->data << " is "
        << (root->left->next? root->left->next->data: -1) << endl;
    cout << "nextRight of " << root->right->data << " is "
        << (root->right->next? root->right->next->data: -1) << endl;
    cout << "nextRight of " << root->left->left->data<< " is "
        << (root->left->left->next? root->left->left->next->data: -1) << endl;
    cout << "nextRight of " << root->right->right->data << " is "
        << (root->right->right->next? root->right->right->next->data: -1) << endl;
    return 0;
}
