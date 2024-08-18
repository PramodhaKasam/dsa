// Implementation of Stack using LinkedList
#include <bits/stdc++.h>
using namespace std;

class Stack{
    public:
        int data;
        struct Stack *next;
    Stack(int val)
    {
        data = val;
        next = nullptr;
    };
};

void BuildStack(Stack** s1)
{
    *s1 = NULL;
}

void push(Stack** s1)
{
    Stack* temp;
    cout<<"Enter the data:";
    int val;
    cin>>val;
    temp = new Stack(val);
    temp -> next = *s1;
    *s1 = temp;
}

void pop(Stack **s1)
{
    if(*s1 != NULL)
    {
        Stack* temp = (*s1);
        *s1 = (*s1) -> next;
        cout<<endl<<temp -> data;
        delete temp;
    }
    else{
        cout<<"\nStack is empty!!";
    }
}

int main()
{
    Stack *s1;
    BuildStack(&s1);
    pop(&s1);
    push(&s1);
    push(&s1);
    pop(&s1);
    return 0;
}
