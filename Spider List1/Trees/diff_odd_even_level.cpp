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

// Time: O(N)
int diffOddEvenLevel1(Node* root){
    if(root==NULL)
        return 0;
    return root->data - diffOddEvenLevel1(root->left) - diffOddEvenLevel1(root->right);
}

/*
    Time: O(N)
    Space: O(N)
*/
int diffOddEvenLevel2(Node* root){
    if(!root)
        return 0;
    queue<Node*> q;
    q.push(root);
    bool odd = true;
    int oddSum = 0, evenSum = 0;
    while(!q.empty()){
        int size = q.size();
        while(size--){
            Node* temp = q.front();
            q.pop();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
            
            (odd==true)?oddSum+=temp->data:evenSum+=temp->data;
        }
        odd = !odd;
    }

    return oddSum-evenSum;
}
int main()
{


    Node *root = newNode(5);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(4);
    root->left->right->left = newNode(3);
    root->right->right = newNode(8);
    root->right->right->right = newNode(9);
    root->right->right->left = newNode(7);
	
    cout<<"Odd even level difference is: "<<diffOddEvenLevel2(root)<<endl;

	return 0;
}

