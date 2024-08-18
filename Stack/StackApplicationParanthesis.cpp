// Use case of stack:
// Checking if the expression has correct paranthesis
#include <bits/stdc++.h>
using namespace std;

class Stack{
    public:
        char data;
        struct Stack *next;
    Stack(char val)
    {
        data = val;
        next = nullptr;
    };
};

void BuildStack(Stack** s1)
{
    *s1 = NULL;
}

void push(Stack** s1, char val)
{
    Stack* temp;
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
        cout<<temp -> data<<endl;
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
    string str;
    cout<<"Enter the string:";
    cin>>str;
    int len = str.size();
    for(int i=0; i<len; i++)
    {
        if(str[i] == '{' || str[i] == '(' || str[i] == '[')
        {
            push(&s1, str[i]);
        }
        else if( str[i] == '}' )
        {
            if( s1 -> data == '{')
                 pop(&s1);
           else{
                cout<<"Error!!\n";
                break;
            }
        }
        else if( str[i] == ']')
        {
           if( s1 -> data == '[')
                 pop(&s1);
            else{
                cout<<"Error!!\n";
                break;
            }
        }
        else if( str[i] == ')')
        {
           if( s1 -> data == '(')
                 pop(&s1);
           else{
                cout<<"Error!!\n";
                break;
            }
        }
        
       
    }
    return 0;
}
