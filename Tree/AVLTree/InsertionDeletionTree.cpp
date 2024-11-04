//Insertion and deletion in AVL Tree
#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *left, *right;
	int height;
};

struct node* createNode(int key)
{
	struct node* newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode ->data = key;
	newnode ->left = newnode ->right = NULL;
	newnode ->height = 1;
}

int getHeight(struct node* root)
{
	if(root == NULL)
		return 0;
	
	return root ->height;
}

int getBalance(struct node* root)
{
	if(root == NULL)
		return 0;
	
	return (getHeight(root ->left) - getHeight(root ->right));
}

struct node* rotateLeft(struct node* &root)
{
	struct node* x = root ->right;
	struct node* y = x ->left;
	
	x->left = root;
	root ->right = y;
	
	root ->height = 1 + max(getHeight(root ->left), getHeight(root ->right));
	x ->height = 1 + max(getHeight(x ->left), getHeight(x ->right));
	
	return x;
}

struct node* rotateRight(struct node* &root)
{
	struct node* x = root ->left;
	struct node* y = x ->right;
	
	x->right = root;
	root ->left = y;
	
	root ->height = 1 + max(getHeight(root ->left), getHeight(root ->right));
	x ->height = 1 + max(getHeight(x ->left), getHeight(x ->right));
	
	return x;
}

struct node* rotateRightLeft(struct node* &root)
{
	root->right = rotateRight(root ->right);
	return rotateLeft(root);
}

struct node* rotateLeftRight(struct node* &root)
{
	root->left = rotateLeft(root ->left);
	return rotateRight(root);	
}

struct node* insert(struct node* &root, int key)
{
	if(root == NULL)
	{
		return createNode(key);
	}
	
	if(root ->data < key)
		root ->right = insert(root ->right , key);
	else if(root ->data > key)
		root ->left = insert(root ->left , key);
	else
		return root;
	
	root ->height = 1 + max(getHeight(root ->right), getHeight(root ->left));
	int balance = getBalance(root);
	
	if(balance > 1 && key < root ->left ->data)
		return rotateRight(root);
	
	if(balance < -1 && key > root ->right ->data)
		return rotateLeft(root);

	if(balance > 1 && key > root ->left ->data)
	{
		return rotateLeftRight(root);
	}
	
	if(balance < -1 && key < root ->right ->data)
	{
		return rotateRightLeft(root);
	}
	
	return root;	
}

void deleteNode(struct node* &root, int key)
{
	if(root == NULL)
		return;
	
	if(root ->data > key)
		deleteNode(root ->left, key);
	else if(root ->data < key)
		deleteNode(root ->right, key);
	else{
		if(root ->left == NULL && root ->right == NULL)
			root = NULL;
		else if(root ->left == NULL && root ->right != NULL)
		{
			root->data = root ->right->data;
			root ->right = NULL;
		}
		else if(root ->left != NULL && root ->right == NULL)
		{
			root->data = root ->left->data;
			root ->left = NULL;
		}
		else
		{
			struct node* temp = root ->right;
			struct node* prev = root;
			while(temp ->left != NULL)
			{
				prev = temp;
				temp = temp ->left;
			}
			root->data = temp->data;
			if(temp == root ->right)
				root ->right = root->right ->right;
			else
				prev ->left = NULL;
		}
	}
}

void inorder( struct node* root)
{
	if(root != NULL)
	{
		inorder(root ->left);
		cout<<root->data<<" ";
		inorder(root ->right);
	}
}

int main()
{
	struct node* root;
	root = NULL;
	int k;
	cout<<"Enter the number of values to get inserted in AVL Tree: ";
	cin>>k;
	for(int i=0; i<k; i++)
	{
		int x;
		cout<<"Enter the value to insert: ";
		cin>>x;
		root = insert(root, x);
	}
	
	cout<<"Inorder traversal of root: ";
	inorder(root);
	
	cout<<"\nEnter a number to delete from tree :";
	int n;
	cin>>n;
	deleteNode(root, n);
	cout<<"Inorder traversal of root after deletion: ";
	inorder(root);
	
	return 0;
}
