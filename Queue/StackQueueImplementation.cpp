// Implementation of Stack using queue
#include <bits/stdc++.h>
using namespace std;
#define size 5

class Queue{
    public:
        int data[size];
        int front;
        int rear;
};

void BuildQueue(Queue* &q1)
{
    q1 = new Queue();
    q1 -> front =-1;
    q1 -> rear = -1;
}

void Enqueue(int x, Queue* &q1)
{
    if(q1 ->front != (q1->rear +1)%size)
    {
        if(q1 ->front == -1 && q1 ->rear == -1)
        {
            q1 ->front =0;
            q1 ->rear = 0;
        }
        else{
            q1 ->rear = (q1 ->rear +1)%size;
        }
        q1 ->data[q1 ->rear] = x;
    }
    else{
        cout<<"ERROR!Overflow!\n";
    }
}

int Dequeue(Queue* &q1)
{
    if(q1 -> front != -1 && q1 ->rear != -1)
    {
        int x = q1 ->data[q1 ->front];
        if(q1 ->rear == q1 ->front)
        {
            q1 ->rear =- 1;
            q1-> front = -1;
        }
        else{
            q1 -> front = (q1 ->front +1)%size;
        }
        return x;
    }
    else{
        cout<<"ERROR!Underflow!!\n";
        return -1;
    }
}

void push(int x, Queue* &q1)
{
    Enqueue(x, q1);
}

int pop(Queue* &q1, Queue* &q2)
{
    while(q1->front != -1 && q1 ->rear != -1)
    {
        int z = Dequeue(q1);
        Enqueue(z, q2);
    }
    int x = Dequeue(q2);
    while(q2 ->front != -1 && q2 ->rear != -1)
    {
        int z = Dequeue(q2);
        Enqueue(z, q1);
    }
    return x;
}

int main()
{
    Queue *q1, *q2;
    BuildQueue(q1);
    BuildQueue(q2);
    push(1, q1);
    push(2, q1);
    push(3, q1);
    cout<<"The popped value : "<<pop(q1, q2)<<endl;
    cout<<"The popped value : "<<pop(q1, q2)<<endl;
    cout<<"The popped value : "<<pop(q1, q2)<<endl;
    push(4, q1);
    cout<<"The popped value : "<<pop(q1, q2)<<endl;
    cout<<"The popped value : "<<pop(q1, q2)<<endl;
    return 0;
}
