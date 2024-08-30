// Implementation of queue using array
#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 10

class Queue {
public:
   int data[MAX_SIZE];
   int front;
   int rear;
};

void BuildQueue(Queue* &q1)
{
    q1 = new Queue();
    q1->front = q1->rear = -1;
}

bool isFull(Queue* &q1)
{
    if(q1->rear == MAX_SIZE - 1)
    {
        return true;
    }
    else{
        return false;
    }
}

bool isEmpty(Queue* &q1)
{
    if(q1->rear <= q1->front )
    {
        return true;
    }
    else
        return false;
}

void Enqueue(Queue* &q1){
    if(!isFull(q1))
    {
        cout<<"Enter a value to enqueue:";
        int val;
        cin>>val;
        q1->rear++;
        q1->data[q1->rear] = val;
        if(q1->front == -1)
        {
            q1 ->front++;
        }
    }
    else{
        cout<<"ERROR! Overflow\n";
    }
}

void Dequeue(Queue* &q1)
{
    if(!isEmpty(q1))
    {
        cout<<"The dequeued value is:"<<q1->data[q1->front]<<endl;
        q1->front++;
    }
    else{
        cout<<"ERROR! Underflow\n";
    }
}

int main() {
    Queue *q1;
    BuildQueue(q1);
    Enqueue(q1);
    Enqueue(q1);
    Enqueue(q1);
    Enqueue(q1);
    Enqueue(q1);

    if (q1->rear != -1) {
        cout << "Rear element: " << q1->data[q1->rear] << endl;
    } else {
        cout << "Queue is empty." << endl;
    }

    Dequeue(q1);
    Dequeue(q1);
    return 0;
}
