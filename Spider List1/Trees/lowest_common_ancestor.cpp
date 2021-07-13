#include<bits/stdc++.h>
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
Node* lca(Node* root, int n1, int n2){
    if(!root)
        return NULL;
    if(root->data == n1 || root->data == n2)
        return root;
    Node* l = lca(root->left, n1, n2);
    Node* r = lca(root->right, n1, n2);
    if(l && r)
        return root;
    return (l!=NULL?l:r);
}

int main()
{


    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout << "LCA(4, 5) = " << lca(root, 4, 5)->data<<endl;;
    cout << "nLCA(4, 6) = " << lca(root, 4, 6)->data<<endl;
    cout << "nLCA(3, 4) = " << lca(root, 3, 4)->data<<endl;
    cout << "nLCA(2, 4) = " << lca(root, 2, 4)->data<<endl;

	return 0;
}

