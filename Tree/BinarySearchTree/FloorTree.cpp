//Floor of a value in BST
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

int floor(int key, node* root)
{
	if(root == NULL)
		return -1;
	
	if(root -> data == key) return root->data;
	
	if(root -> data > key) return floor(key, root->left);
	
	int floorv = floor(key, root->right);
	
	return (floorv <= key && floorv != -1)? floorv : root ->data;
}
 
 
int main() {
    node* root;
    root  = createNode(10);
    root ->left = createNode(5);
    root ->right = createNode(15);
    root->right->left = createNode(12); 
    root ->right->right = createNode(20);
    
    cout<< floor(1, root);
    return 0;
}
