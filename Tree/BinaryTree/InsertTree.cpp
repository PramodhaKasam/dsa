//Insertion in Binary Tree
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

node* insert(node* root, int data) {
    if (!root) 
    {
		root = createNode(data);
		return root;
	}
    
	queu* q;
    q = buildQueue(q, 10);
    Enqueue(q, root);

    while (q->front != -1) {
        node* temp = Dequeue(q);
        cout << temp->data << " ";
        if (temp->left != NULL)
            Enqueue(q, temp->left);
		else
		{
			temp ->left = createNode(data);
			return root;
		}
        if (temp->right != NULL)
            Enqueue(q, temp->right);
        else{
			temp ->right = createNode(data);
			return root;
			
		}
    }
    return root;
}

void inorder(node* root)
{
	if(root != NULL)
	{
		cout<<root ->data<<" ";
		inorder(root ->left);
		
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
    
    root = insert(root, 8);
    inorder(root);
    return 0;
}
