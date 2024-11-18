//Inorder predecessor of a value in BST
#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *left, *right;
};

node* createNode(int val)
{
	node* temp;
	temp = (node*)malloc(sizeof(node));
	temp ->data = val;
	temp ->left = temp ->right = NULL;
	return temp;
}

int rightmost(node* root)
{
	node* temp = root;
	while(root ->right != NULL)
		temp = temp->right;
	return temp->data;
}

int inordPred(node* root, int val)
{
	if(root == NULL)return -1;
	
	if(root ->data == val)
		return rightmost(root ->left);
	
	node* pred = NULL;
	node* curr = root;
	
	while(curr != NULL)
	{
		if(curr ->data > val)
			curr = curr ->left;
		
		else if(curr ->data < val)
		{
			pred = curr;
			curr = curr ->right;
		}
		
		else
			break;
	}
	if(pred)
	 return pred->data;
	else
	 return -1;
} 
 
int main() {
    node* root;
    root  = createNode(10);
    root ->left = createNode(5);
    root ->right = createNode(15);
    root->right->left = createNode(12); 
    root ->right->right = createNode(20);
    
    cout<< inordPred(root, 1);
    return 0;
}
