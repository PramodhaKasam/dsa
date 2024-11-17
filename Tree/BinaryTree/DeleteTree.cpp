//Deletion in Binary Tree
#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *left, *right;
};
struct queu{
    node** data; 
    int front, rear, size;
};

node* createNode(int key) {
    node* temp = new node();
    temp->data = key;
    temp->left = temp->right = NULL;
    return temp;
}
queu* buildQueue(queu* q, int size) {
	q = (queu*)malloc(sizeof(queu));
    q->data = new node*[size];
    q->front = q->rear = -1;
    q->size = size;
    return q;
}

void Enqueue(queu* &q, node* root) {
    if ((q->rear + 1) % q->size != q->front) { 
        if (q->front == -1)
            q->front = 0;
        q->rear = (q->rear + 1) % q->size;
        q->data[q->rear] = root;
    }
}

node* Dequeue(queu* &q) {
    if (q->front == -1) { 
        return NULL;
    }
    node* z = q->data[q->front];
    if (q->front == q->rear) { 
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->size;
    }
    return z;
}

void delet(node* &root, int key)
{
	node* temp = root; 
	node* prev;
	while(temp ->right != NULL)
	{
		prev = temp;
		temp = temp ->right;
	}
	prev ->right = NULL;
	
	if(temp ->data == key)
		return;

	
	queu* q;
	q = buildQueue(q, 10);
	Enqueue(q, root);
	while(q->front != -1)
	{
		prev = Dequeue(q);
		if(prev ->data == key)
		{
			prev ->data = temp ->data;
			return;
		}	
		if(prev ->left != NULL)
		{
			Enqueue(q, prev->left);
		}
		
		if(prev ->right != NULL)
			Enqueue(q, prev->right);
	}
}



void inorder(node* root)
{
	if(root != NULL)
	{
		inorder(root ->left);
		cout<<root ->data<<" ";
		inorder(root ->right);
	}
}

int main() {
    node* root;
    root  = createNode(4);
    root ->left = createNode(5);
    root->left->left = createNode(3);
    root ->right = createNode(7);
    root ->right->right = createNode(10);
    
    inorder(root);
    
    delet(root, 5);
    cout<<endl;
    inorder(root);
    return 0;
}
