//Deletion of a node in BST
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
	Node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

void inorder(struct Node* root)
{
	struct Node* temp = root;
	if(temp != NULL)
	{
		inorder(temp ->left);
		cout<<temp->data<<" ";
		inorder(temp->right);
	}
}

struct Node* insertTree(struct Node* root, int num)
{
	if(root == NULL)
		return new Node(num);
	
	if(root ->data > num)
		root ->left = insertTree(root->left, num);
	else
		root ->right = insertTree(root ->right, num);
	
	return root;
}

void deleteTree(struct Node* root, int num)
{
	if(root == NULL)
	return;
	
	if(root ->data > num)
		deleteTree(root ->left, num);
	else if(root ->data > num)
		deleteTree(root->right, num);
	else{
		if(root ->left == NULL && root ->right != NULL)
		{
			root ->data = root ->right ->data;
			root ->right = NULL;
		}
		else if(root ->left != NULL && root ->right == NULL)
		{
			root ->data = root ->left ->data;
			root ->left = NULL;
		}
		else{
			struct Node *temp, *prev;
			temp = root ->left;
			prev = root;
			while(temp->right != NULL)
			{
				prev = temp;
				temp = temp ->right;
			}
			
			if(prev == root)
			{
				root->data = temp ->data;
				prev ->left = NULL;
			}
			else{
				root ->data = temp ->data;
				prev ->right = NULL;
			}
		}					
	}
}

int main()
{
	struct Node* root;
	root = NULL;
	root =insertTree(root , 3);
	root =insertTree(root , 4);
	root =insertTree(root , 6);
	root =insertTree(root , 1);
	root =insertTree(root , 2);
	root = insertTree(root , 9);
	
	cout<<"Inoder traversal of Tree: ";
	inorder(root);
	
	deleteTree(root, 1);
	cout<<"\nInoder traversal of Tree after deletion: ";
	inorder(root);
	
	
	
	return 0;
}
