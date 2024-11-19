//Transpose of graph in adjacency matrix
#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* next;
};

void addEdge(vector <vector<int>> &arr, int i, int j)
{
	if(arr[i][j] == 0)
		arr[i][j]++;
}

void transpose(vector <vector<int>> &arr, vector <vector<int>> &trans, int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(arr[i][j] == 1)
				trans[j][i] =1;
		}
	}
}

void display(vector <vector<int>> &arr, int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}
}

int main()
{
	int n;
	cin>>n;
	vector <vector<int>> arr(n, vector<int>(n, 0));
	
	addEdge(arr, 0, 4);
	addEdge(arr, 0, 2);
	addEdge(arr, 3, 4);
	
	display(arr, n);
	cout<<endl;
	vector <vector<int>> trans(n, vector<int>(n, 0));
	transpose(arr, trans, n);
	display(trans, n);
	return 0;
}
