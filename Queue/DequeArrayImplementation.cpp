// implementation of deque using an array
#include<bits/stdc++.h>
using namespace std;
#define size 5

struct Deque{
	int data[size];
	int front;
	int rear;
};

void BuildDeque(struct Deque* &q1)
{
	q1 = (struct Deque*)malloc(sizeof(struct Deque));
	q1 ->front = -1;
	q1 ->rear = -1;
}

bool isFull(struct Deque* &q1)
{
	if(q1 -> front == (q1 ->rear +1)%size)
		return 1;
	else
		return 0;
}

bool isEmpty(struct Deque* &q1)
{
	if(q1 -> front == -1 && q1 -> rear == -1)
	{
		return 1;
	}
	else{
		return 0;
	}
}

void insertFront(struct Deque* &q1, int x)
{
	if(!isFull(q1))
	{
		if(q1 ->front == -1 && q1 ->rear == -1)
		{
			q1 ->front = q1 ->rear = 0;
		}
		else{
			q1 ->front = (q1 ->front -1 + size)%size;
		}
		q1 -> data[q1 -> front] = x;
	}
	else{
		cout<<"ERROR! Overflow!\n";
	}
}

void insertRear(struct Deque* &q1, int x)
{
	if(!isFull(q1))
	{
		if(q1 -> front == -1 && q1 -> rear == -1)
		{
			q1 -> rear = q1 -> front = 0;
		}
		else{
			q1 -> rear = (q1 -> rear + 1)%size;
		}
		q1 -> data[q1 -> rear] = x;
	}
	else{
		cout<<"ERROR! Overflow!\n";
	}
}

int deleteFront(struct Deque* &q1)
{
	if(!isEmpty(q1))
	{
		int z;
		z = q1 ->data[q1 -> front];
		if(q1 -> front == q1 -> rear)
		{
			q1 ->front = q1 -> rear = -1;
		}
		else{
			q1 ->front = (q1 ->front +1)%size;
		}
		return z;
	}
	else{
		return 0;
	}
}

int deleteRear(struct Deque* &q1)
{
	if(!isEmpty(q1))
	{
		int z;
		z = q1 ->data[q1 -> rear];
		if(q1 -> front == q1 -> rear)
		{
			q1 ->front = q1 -> rear = -1;
		}
		else{
			q1 ->rear = (q1 ->rear -1 + size)%size;
		}
		return z;
	}
	else{
		return 0;
	}
}

void printDeque(struct Deque* q1)
{
	if(isEmpty(q1))
	{
		cout<<"Deque is empty\n";
	}
	else{
		cout<<"Deque from the front: ";
		int z;
		for(z = q1 ->front; z != q1 ->rear; z = (z + 1)%size)
		{
			cout<<q1 ->data[z]<<" ";
		}
		cout<<q1 ->data[z]<<" ";
		cout<<endl;
		cout<<"Deque from the rear: ";
		for(z = q1 -> rear; z != q1 ->front; z = (z-1 + size)%size )
		{
			cout<<q1 ->data[z]<<" ";
		}
		cout<<q1 ->data[z]<<" ";
		cout<<endl;
	}
}

int main()
{
	struct Deque* q1;
	BuildDeque(q1);
	cout<<"The deque is empty: "<<isEmpty(q1)<<endl;
	cout<<"The deque is full: "<<isFull(q1)<<endl;

	cout<<"The deleted value from the front is: "<<deleteFront(q1)<<endl;
	cout<<"The deleted value from the rear is: "<<deleteRear(q1)<<endl;
	
	insertFront(q1, -2);
	insertFront(q1, -5);
	insertRear(q1, 3);
	insertRear(q1, -3);
	insertRear(q1, 9);
	insertRear(q1, 8);
	
	printDeque(q1);
	
	cout<<"The deleted value from the front is: "<<deleteFront(q1)<<endl;
	cout<<"The deleted value from the front is: "<<deleteFront(q1)<<endl;
	cout<<"The deleted value from the front is: "<<deleteFront(q1)<<endl;
	cout<<"The deleted value from the rear is: "<<deleteRear(q1)<<endl;
	
	return 0;
}
