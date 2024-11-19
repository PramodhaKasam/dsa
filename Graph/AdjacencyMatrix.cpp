//Representation of graphs in adjacency matrix
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector <vector<int>> &arr, int i, int j)
{
	if(arr[i][j] == 0)
		arr[i][j] = arr[j][i] = 1;
}

void display(vector <vector<int>> arr, int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j =0; j<n; j++)
			cout<<arr[i][j]<< " ";
		cout<<endl;
	}
}


int main()
{
	int n;
	cin>>n;
	vector <vector<int>> arr(n, vector<int>(n, 0));
	
	addEdge(arr, 0, 5);
	
	display(arr, n);
	return 0;
}
