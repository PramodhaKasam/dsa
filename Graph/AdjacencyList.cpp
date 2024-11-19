//Representation of graphs in adjacency list
#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* next;
};

node* createNode(int val)
{
	
	node* temp;
	temp = (node*)malloc(sizeof(node));
	temp ->data = val;;
	temp ->next = NULL;
	return temp;
}

void addEdge(node* arr[], int i, int j)
{
	if(arr[i] == NULL)
		arr[i] = createNode(j);
	else{
		node* temp;
		temp = arr[i];
		while(temp ->next != NULL)
			temp = temp->next;
		temp ->next = createNode(j);
	}
	
	if(arr[j] == NULL)
		arr[j] = createNode(i);
	else
	{
		node* temp;
		temp = arr[j];
		while(temp ->next != NULL)
			temp = temp->next;
		temp ->next = createNode(i);
	}
}

void display(node* arr[], int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<"Node "<<i<<"-> ";
		node* temp = arr[i];
		while(temp != NULL)
		{
			cout<<temp->data<<"-> ";
			temp= temp->next;
		}
		cout<<endl;
	}
}

int main()
{
	int v;
	cin>>v;
	node* arr[v];
	
	for(int i=0; i<v; i++)
		arr[i] = NULL;
	
	addEdge(arr, 0, 5);
	addEdge(arr, 0, 2);
	addEdge(arr, 3, 4);
	
	display(arr, v);
	return 0;
}
