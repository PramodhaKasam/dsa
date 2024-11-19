//DFS of disconnected graph in adjacency list
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
}

void dfsrec(node* arr[], vector <bool>& visited, int s)
{
	visited[s] = true;
	cout<<s<<" ";
	
	if(arr[s] != NULL)
	{
		node* temp = arr[s];
		while(temp != NULL)
		{
			if(!visited[temp ->data])
			{
				dfsrec(arr, visited, temp->data);
			}
			temp = temp->next;	
		}
	}
}

void dfs(node* arr[], int n)
{
	vector <bool> visited(n, false);
	for(int i=0; i<n; i++)
	{
		if(!visited[i])
			dfsrec(arr, visited, i);
	}
	
}

int main()
{
	int v = 6;
	node* arr[v];
	
	for(int i=0; i<v; i++)
		arr[i] = NULL;
	
	addEdge(arr, 0, 2);
	addEdge(arr, 0, 5);
	addEdge(arr, 2, 4);
	
	dfs(arr, v);
	
	return 0;
}
