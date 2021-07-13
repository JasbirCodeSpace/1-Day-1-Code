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

bool checkUtil(Node* root, int level, int& leafLevel){
    if(root==NULL)
        return true;
    if(!root->left && !root->right){
        if(leafLevel==-1){
            leafLevel = level;
            return true;
        }
        return level == leafLevel;
    }
    return checkUtil(root->left, level+1, leafLevel) && checkUtil(root->right, level+1, leafLevel);
}

// Time: O(N)
bool checkSameLevel1(Node* root){
    int level=0, leaflevel=-1;
    return checkUtil(root, level, leaflevel);
}

/*
    Time: O(N)
    Space: O(N)
*/
bool checkSameLevel2(Node* root){
    if(!root)
        return true;
    queue<Node*> q;
    q.push(root);

    int level = 0, leaflevel = -1;
    while(!q.empty()){
        int size = q.size();
        level++;

        while(size--){
            Node* temp = q.front();
            q.pop();

            if(!temp->left && !temp->right){
                if(leaflevel==-1){
                    leaflevel = level;
                }
                else if(level != leaflevel)
                    return false;
            }
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    return true;
}
int main()
{


    Node *root = newNode(12);
    root->left = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(9);
    root->left->left->left = newNode(1);
    root->left->right->left = newNode(1);
	
    cout<<"All leaves are at same level?: "<<checkSameLevel2(root)<<endl;

	return 0;
}

