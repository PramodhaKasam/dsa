#include <bits/stdc++.h>
using namespace std;
#define size 5

struct Stacks{
	int data[size];
	int top1;
	int top2;
};

void BuildStacks(struct Stacks* &s12)
{
	s12 = (struct Stacks*)malloc(sizeof(struct Stacks));
	s12 ->top1 = -1;
	s12 ->top2 =size;
}

bool isFull(struct Stacks* &s12)
{
	if(s12 ->top1 +1 == s12 ->top2)
	{
		return 1;
	}
	else
		return 0;
}

bool isEmpty1(struct Stacks* &s12)
{
	if(s12 ->top1 == -1)
	{
		return 1;
	}
	else
		return 0;
}

bool isEmpty2(struct Stacks* &s12)
{
	if(s12 ->top2 == size)
	{
		return 1;
	}
	else
		return 0;
}

void push1(struct Stacks* &s12, int val)
{
	if(!isFull(s12))
	{
		s12 ->top1++;
		s12 ->data[s12 ->top1] = val;
	}
	else{
		cout<<"ERROR! Overflow\n";
	}	
}

void push2(struct Stacks* &s12, int val)
{
	if(!isFull(s12))
	{
		s12 ->top2--;
		s12 ->data[s12 ->top2] = val;
	}
	else{
		cout<<"ERROR! Overflow\n";
	}	
}

int pop1(struct Stacks* &s12)
{
	if(!isEmpty1(s12))
	{
		int x = s12 ->data[s12->top1];
		s12 ->top1--;
		return x;
	}
	else{
		return -1;
	}
}

int pop2(struct Stacks* &s12)
{
	if(!isEmpty2(s12))
	{
		int x = s12 ->data[s12->top2];
		s12 ->top2++;
		return x;
	}
	else{
		return -1;
	}	
}

void printstack1(struct Stacks* &s12)
{
	if(!isEmpty1(s12))
	{
		for(int i=0; i<= s12->top1; i++)
		{
			cout<<s12 ->data[i]<<" ";
		}
		cout<<endl;		
	}
	else
		cout<<"Stack is empty!!\n";
	
}

void printstack2(struct Stacks* &s12)
{
	if(!isEmpty2(s12))
	{
		for(int i=size -1; i >= s12->top2; i--)
		{
			cout<<s12 ->data[i]<<" ";
		}
		cout<<endl;		
	}
	else
		cout<<"Stack is empty!!\n";
	
}

int main()
{
	struct Stacks* s12;
	BuildStacks(s12);
	
	push1(s12, 1);
	push1(s12, 3);
	push1(s12, 5);
	push2(s12, 6);
	push2(s12, 7);
	push2(s12, 8);
	
	cout<<"The element popped from stack1 is: "<<pop1(s12)<<endl;
	cout<<"The element popped from stack2 is: "<<pop2(s12)<<endl;
	
	push2(s12, 7);
	push2(s12, 8);
	
	cout<<"Stack1 is empty: "<<isEmpty1(s12)<<endl;
	cout<<"Stack2 is empty: "<<isEmpty2(s12)<<endl;
	cout<<"Array is full: "<<isFull(s12)<<endl;
	
	cout<<"The elements of stack1 are: ";
	printstack1(s12);
	cout<<"The elements of stack2 are: ";
	printstack2(s12);
	return 0;
}
//Implement 2 stacks S1, S2 using a single array without wasting any memory. You need to decide the
//”overflow” and ”underflow” conditions. You need to implement the following functions:
//(a) push (5)
//(b) pop (5)
//(c) isEmpty (5)
//(d) isFull (5)
//(e) printStack
