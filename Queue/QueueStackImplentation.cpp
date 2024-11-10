// Implementation of queue using stack
#include <bits/stdc++.h>
using namespace std;
#define size 5

class Stack{
    public:
        int data[size];
        int top;
};

void BuildStack(Stack* &s1)
{
    s1 = new Stack();
    s1 -> top = -1;
}

void push(Stack* &s1, int x)
{
    if(s1 ->top != size-1)
    {
        s1 ->top++;
        s1 -> data[s1 -> top] = x;
    }
    else{
        cout<<"ERROR!Overflow!!\n";
    }
}

int pop(Stack* &s1)
{
    if(s1->top != -1)
    {
        int x = s1 ->data[s1 ->top];
        s1 ->top--;
        return x;
    }
    else{
        cout<<"ERROR!Underflow!!\n";
        return -1;
    }
}

void Enqueue(int x, Stack* &s1)
{
    push(s1, x);
}

int Dequeue(Stack* &s1, Stack* &s2)
{
    while(s1 -> top != -1)
    {
        int z = pop(s1);
        push(s2, z);
    }
    int x = pop(s2);
    while(s2 -> top != -1)
    {
        int z = pop(s2);
        push(s1, z);
    }
    return x;
}

int main()
{
    Stack *s1, *s2;
    BuildStack(s1);
    BuildStack(s2);
    Enqueue(3, s1);
    Enqueue(2, s1);
    Enqueue(4, s1);
    cout<<"The dequeued value : "<<Dequeue(s1, s2)<<endl;
    cout<<"The dequeued value : "<<Dequeue(s1, s2)<<endl;
    Enqueue(5, s1);
    cout<<"The dequeued value : "<<Dequeue(s1, s2)<<endl;
    cout<<"The dequeued value : "<<Dequeue(s1, s2)<<endl;
    cout<<"The dequeued value : "<<Dequeue(s1, s2)<<endl;
    
    return 0;
}
