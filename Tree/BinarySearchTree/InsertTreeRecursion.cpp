// Insertion in binary tree through recursion 
#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left, *right;
};

struct node* createNode(int val)
{
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode ->data = val;
    newnode ->left = newnode ->right = NULL;
    return newnode;
}

struct node* insertTree(struct node* &root, int val)
{
    if(root == NULL)
    {
        root = createNode(val);
        return root;
    }
    
    if(root ->data > val)
    {
        insertTree(root -> left, val);
    }
    else{
        insertTree(root ->right, val);
    }
    
    return root;
}

void display(struct node* root)
{
    if(root != NULL)
    {
        cout<<root ->data<<" ";
        display(root ->left);
        display(root ->right);
    }
}

int main()
{
    struct node* root;
    root = NULL;
    root = insertTree(root, 9);
    root = insertTree(root, 10);
    root = insertTree(root, 7);
    root = insertTree(root, 6);
    root = insertTree(root, 8);
    root = insertTree(root, 2);
    root = insertTree(root, 4);
    
    cout<<"The tree:\n";
    display(root);
    return 0;
}
