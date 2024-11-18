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

void inorder(node* root, int arr[], int& i)
{
	if(root != NULL)
	{
		inorder(root->left, arr, i);
		arr[i++] = root->data;
		inorder(root->right, arr, i);	
	}
}

int inordPred(node* root, int val, int size)
{
	int arr[size];
	int index = 0;
	inorder(root, arr, index);
	
	if(arr[0] == val)
		return -1;
	for(int i=1; i<size; i++)
	{
		if(arr[i] == val)
			return arr[i-1];
	}
}
  
int main() {
    node* root;
    root  = createNode(10);
    root ->left = createNode(5);
    root ->right = createNode(15);
    root->right->left = createNode(12); 
    root ->right->right = createNode(20);
    
    cout<< inordPred(root, 15, 5);
    return 0;
}


