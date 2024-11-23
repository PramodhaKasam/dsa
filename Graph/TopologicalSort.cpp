//Topological sort of a graph
#include <bits/stdc++.h>
#define e 4
#define v 5
using namespace std;

void topologyHelp(int* adj, bool visited[], stack <int>& s, int i)
{
	visited[i] = true;
	
	for(int j=0; j<v; j++)
	{
		if(*((adj + i*v)+ j) && !visited[j])
			topologyHelp(adj, visited, s, j);
	}
	
	s.push(i);
}

void topology(int* adj)
{
	bool visited[v];
	for(int i=0; i<v; i++)
		visited[i] = false;
	
	stack <int> s;
	for(int i=0; i<v; i++)
	{
		if(visited[i] == false)
		{
			topologyHelp(adj, visited, s, i);
		}
	}
	
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
}

int main()
{
	int grap[e][2] = {{0, 3}, {2, 1}, {3, 1}, {2, 4}};
	
	int adj[v][v];
	for(int i=0; i<v; i++)
	{
		for(int j=0; j<v; j++)
			adj[i][j] = 0;
	}
	
	for(int i=0; i<e; i++)
		adj[grap[i][0]][grap[i][1]] =1;
	
	topology((int*)adj);
	return 0;
}
