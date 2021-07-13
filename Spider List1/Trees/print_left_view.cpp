#include<iostream>
using namespace std;

class Node
{   public:
	int data;
	Node *left, *right;
};

Node* newNode(int data)
{
	Node *temp = new Node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// T(n) = O(n)
void _printLeftView(Node* root, int level, int &maxlevel){
    if(!root)
        return;
    if(maxlevel<level){
        cout<<root->data<<' ';
        maxlevel = level;
    }
    _printLeftView(root->left, level+1, maxlevel);
    _printLeftView(root->right, level+1, maxlevel);
}

void printLeftView(Node* root){
    int level = 1, maxlevel = 0;
    _printLeftView(root, level, maxlevel);
}
int main(int argc, char const *argv[])
{
    Node* root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(8);
    root->right->right = newNode(15);
    root->right->left = newNode(12);
    root->right->right->left = newNode(14);
    printLeftView(root);
    cout<<endl;
    return 0;
}
