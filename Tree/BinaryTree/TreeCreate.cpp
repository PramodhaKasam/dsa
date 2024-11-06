// Code for building a tree and verified using inorder traversal
#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left, *right;
};

struct node* buildTree()
{
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    int val;
    cout<<"Enter the data in the node(-1 for no node):";
    cin>>val;
    if(val == -1)
        return 0;
    newnode ->data = val;
    newnode ->left = NULL;
    newnode ->right = NULL;
    
    cout<<"For the left child:\n" ;
    newnode ->left = buildTree();
    cout<<"For the right child:\n ";
    newnode ->right = buildTree();
    return newnode;
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
    struct node * root ;
    root = NULL;
    root =  buildTree();
    cout<<"The tree is : \n";
    display(root);
    return 0;
}
