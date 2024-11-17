//Level order traversal
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

node* insert(node* root, int key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
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

void levelorder(node* root) {
    if (!root) return;
	queu* q;
    q = buildQueue(q, 5);
    Enqueue(q, root);

    while (q->front != -1) {
        node* temp = Dequeue(q);
        cout << temp->data << " ";
        if (temp->left != NULL)
            Enqueue(q, temp->left);
        if (temp->right != NULL)
            Enqueue(q, temp->right);
    }
}

int main() {
    node* root = NULL;
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 4);
    levelorder(root);
    return 0;
}
