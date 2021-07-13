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

void verticalSumUtil(Node* root, int d, map<int, int>& m){
    if(!root)
        return;
    verticalSumUtil(root->left, d-1, m);
    m[d]+=root->data;
    verticalSumUtil(root->right, d+1, m);
}

// T(n) = O(n)
// Space: O(N)
void verticalSum(Node* root){
    if(!root)
        return ;
    map<int, int> m;
    verticalSumUtil(root, 0, m);

    for(auto i=m.begin(); i!=m.end(); i++){
        cout<<i->first<<' '<<i->second<<endl;
    }
}
int main()
{

	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->left->right = newNode(8);
	root->right->right->right = newNode(9);

	cout << "Following are the values of vertical"
			" sums with the positions of the "
			"columns with respect to root\n";
	verticalSum(root);

	return 0;
}

