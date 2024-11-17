//ceil of a value in BST
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

int ceils(int key, node* root)
{
	if(root == NULL)
		return -1;
	
	if(root -> data == key) return root->data;
	
	if(root -> data < key) return ceils(key, root->right);
	
	int ceilv = ceils(key, root->left);
	
	return (ceilv >= key && ceilv != -1)? ceilv : root ->data;
}
 
 
int main() {
    node* root;
    root  = createNode(10);
    root ->left = createNode(5);
    root ->right = createNode(15);
    root->right->left = createNode(12); 
    root ->right->right = createNode(20);
    
    cout<< ceils(25, root);
    return 0;
}
