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

/*
    Time: O(N)
    Space: O(N)
*/
void zigZagTraversal(Node* root){

    if(!root)
        return;
    
    stack<Node*> s1;    // left to right
    stack<Node*> s2;    // right to left
    s1.push(root);

    while(!s1.empty() || !s2.empty()){

        while(!s1.empty()){
            Node* temp = s1.top();
            cout<<temp->data<<' ';
            s1.pop();
            if(temp->left)
                s2.push(temp->left);
            if(temp->right)
                s2.push(temp->right);

        }

        while(!s2.empty()){
            Node* temp = s2.top();
            cout<<temp->data<<' ';
            s2.pop();
            if(temp->right)
                s1.push(temp->right);
            if(temp->left)
                s1.push(temp->left);
        }
    }
    cout<<endl;
}
int main()
{


    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    cout << "ZigZag Order traversal of binary tree is \n";
    zigZagTraversal(root);
	return 0;
}

