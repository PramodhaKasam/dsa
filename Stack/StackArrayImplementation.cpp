// Implementation of Stack using array
#include <bits/stdc++.h>
using namespace std;

class Stack{
    public:
        int top;
        int size;
        int *elements;
    Stack(int val)
    {
        top = -1;
        size = val;
        elements = nullptr;
    };
};

void BuildStack(int n, Stack** s1)
{
    *s1 = new Stack(n);
    (*s1) -> elements = (int *)malloc(n*sizeof(int));
}

void push(Stack** s1)
{
    if((*s1) -> top != (*s1) -> size -1)
    {
        cout<<"Enter data:";
        int data;
        cin>>data;
        (*s1) ->top++;
        (*s1) -> elements[(*s1) ->top] = data;
    }
    else{
        cout<<"\nStack is full!!";
    }
}

void pop(Stack** s1)
{
    if((*s1) -> top == -1)
    {
        cout<<"\nStack is empty!!";
    }
    else{
         cout<< (*s1) -> elements[(*s1)->top];
         (*s1 ) ->top--;
    }
}

bool isEmpty(Stack* s1)
{
    if(s1 -> top == -1)
    {
        return true;
    }
    else{
        return false;
    }
}

bool isFull(Stack* s1)
{
    if(s1 -> top == s1-> size-1)
    {
        return true;
    }
    else
        return false;
}

void getTop(Stack* s1)
{
    if(s1 -> top == -1)
    {
        cout<<"Stcak is empty!!";
    }
    else{
        cout<< s1-> elements[s1-> top];
    }
}

int main()
{
    int n;
    Stack *s1;
    cout<<"Enter the size of the Stack:";
    cin>>n;
    BuildStack(n, &s1);
    cout<<"Is stack empty : "<<isEmpty(s1);
    push(&s1);
    push(&s1);
    push(&s1);
    push(&s1);
    pop(&s1);
    getTop(s1);
    cout<<"Is stack full: "<< isFull(s1);
    return 0;
}
