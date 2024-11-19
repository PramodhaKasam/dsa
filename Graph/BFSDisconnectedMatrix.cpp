//BFS of disconnected graph in adjacency matrix
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector <vector<int>> &arr, int i, int j)
{
	if(arr[i][j] == 0)
		arr[i][j]++;
}

void bfs(vector <vector<int>> arr, vector <bool> &visited, int s, int n)
{
	visited[s] = true;
	
	queue <int> q;
	q.push(s);
	
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
		cout<<curr<<" ";
		
		for(int i=0; i<n; i++)
		{
			if(arr[curr][i] == 1 && visited[i] != true)
			{
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

void bfshelper(vector <vector<int>> arr, int n)
{
	vector <bool> visited(n, false);
	
	for(int i=0; i<n; i++)
	{
		if(!visited[i])
			bfs(arr, visited, i, n);
	}
}

int main()
{
	int n =5;
	vector <vector<int>> arr(n, vector<int>(n, 0));
	
	addEdge(arr, 0, 4);
	addEdge(arr, 0, 2);
	addEdge(arr, 3, 4);
	addEdge(arr, 2, 1);
	
	bfshelper(arr, n);
	
	return 0;
}
