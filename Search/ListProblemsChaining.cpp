#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *next;
};

void buildList(struct node* &head, int n){
	struct node *temp;
	for(int i=0; i<n; i++)
	{
		struct node* newnode;
		newnode = (struct node*)malloc(sizeof(struct node));
		int val;
		cout<<"Enter the value in node "<<i+1<<" :";
		cin>>val;
		newnode ->data = val;
		newnode ->next = NULL;
		if(head == NULL)
		{
			temp = head = newnode;
		}
		else{
			temp ->next = newnode;
			temp = newnode;
		}
	}
	
}

void display(struct node* &head)
{
	struct node *temp = head;
	while(temp != NULL)
	{
		if(temp ->next != NULL)
			cout<<temp ->data<<" - > ";
		else
			cout<<temp->data;
		temp = temp ->next;
	}
	cout<<endl;
}

void reverseSpecific(struct node* &head, int n, int k)
{
	struct node *temp= head;
	struct node *prev, *nnode, *point;
	prev = NULL;
	point = temp;
	for(int j=0; j<n/k; j++)
	{	
		struct node *founder;
		founder = temp;
		prev = NULL;
		for(int i=0; i<k; i++)
		{
			nnode = temp ->next;
			temp ->next = prev;
			prev = temp;
			temp = nnode;	
		}
		if(j != 0)
		{
			point->next = prev;
			point = founder;
		}
		if(j == 0)
		{
			head = prev;
		}
		founder ->next = nnode;
		founder = temp;
	}
}

void checkElement(struct node* &head, struct node* hashTable[])
{
	struct node *temp = head;
	struct node *prev;
	while(temp != NULL)
	{
		int hash = temp->data %10;
		int point =0;
		struct node* newnode;
		newnode = (struct node*)malloc(sizeof(struct node));
		newnode ->next = NULL;
		newnode ->data = temp ->data;
		if(hashTable[hash] == NULL)
		{
			hashTable[hash] = newnode;
		}
		else{
			struct node* temp2;
			temp2 = hashTable[hash];
			while(temp2 != NULL)
			{
				if(temp2 ->data == newnode ->data)
				{
					prev ->next = temp ->next;
					temp = temp ->next;
					point = 1;
					break;
				}
				temp2 = temp2 ->next;
			}
		}		
		if(point != 1){
			prev = temp;
			temp = temp ->next;
		}		
	}
}

int main()
{
	int n, k;
	cout<<"Enter the number of nodes in linked list and the number of elements to reverse: ";
	cin>>n>>k;
	struct node *head;
	head = NULL;
	buildList(head, n);
	cout<<"Original linkedlist:";
	display(head);
	if(k <= n)
	{
		reverseSpecific(head, n, k);
		cout<<"Linked list after reversal: ";
		display(head);
	}
	else
		cout<<"ERROR! k > n";
	cout<<endl;
	
	struct node *head2;
	head2 = NULL;
	int n2;
	cout<<"Size of linkedlist: ";
	cin>>n2;
	buildList(head2, n2);
	cout<<"Original linkedlist:";
	display(head2);
	struct node* hashTable[10];
	for(int i=0; i<10; i++)
		hashTable[i] = NULL;
	checkElement(head2, hashTable);
	cout<<"Linked list after removal of duplicates: ";
	display(head2);
	
	return 0;
}

//1. Build a singly linked list by taking integer inputs from the user. Given the head of that singly linked
//list of n nodes and a given integer k, where k is less than or equal to n. Your task is to reverse the
//order of each group of k consecutive nodes, if n is not divisible by k, then the last group of remaining
//nodes should remain unchanged. (25)
//2. Use the linked list constructed in the previous problem and remove the duplicate elements from the
//list using a hash table where collision resolution is done using chaining. To solve this problem you
//need to implement the following steps: (25)
//(a) Create the input singly linked list using the function implemented to solve problem 1.
//(b) Create a hash table where collision resolution is done using chaining.
//(c) Traverse the linked list and insert the integer into the hash table fs that is not already present.
//If it is already present in the hash table, then delete that node from the linked list.
