// Writing minimum spanning tree using prims algorithm
#include <bits/stdc++.h>
#define v 5
using namespace std;

int minkey(int key[], bool mst[])
{
	int min = INT_MAX, min_index =-1;
	for(int i=0; i<v; i++)
	{
		if(key[i] < min && mst[i] == false)
			min_index = i, min = key[i];
	}
	return min_index;
}

void printMST(int parent[], int key[])
{
	cout<<"EDGE - PARENT \n";
	
	for(int i=0; i<v; i++)
	{
		cout<<i<<" - "<<parent[i]<< "\t" << key[i]<<endl;
	}
}

void MST(int* grap)
{
	int key[v];
	int parent[v];
	bool mst[v];
	
	for(int i=0; i<v; i++)
		mst[i] = false, key[i] = INT_MAX;
	
	key[0] =0;
	parent[0] = -1;
	
	for(int i = 0; i<v; i++)
	{
		int u = minkey(key, mst);
		mst[u] = true;
		
		for(int j=0; j<v; j++)
		{
			int k = *((grap+ i*v) + j);
			if( k && k < key[j])
			{
				key[j] = k;
				parent[j] = i;
			}
		}
	}
	
	printMST(parent, key);
}

int main()
{
	int grap[v][v] = {{0, 2, 4, 8, 9}, 
					{2, 0, 4, 5, 4},
					{3, 5, 0, 7, 9}, 
					{5, 6, 1, 0, 3}, 
					{1, 2, 6, 7, 0}};
	MST((int*)grap);
	return 0;
}
