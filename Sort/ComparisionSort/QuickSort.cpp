//Quick sort algorithm
#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high)
{
	int pivot = arr[low];
	int down = low;
	int up = high;
	
	while(down < up)
	{
		while(arr[down] <= pivot && down < up)
			down++;
		
		while(arr[up]> pivot)
			up--;
			
		if(up > down)
			swap(arr[up], arr[down]);
	}
	swap(arr[low], arr[up]);
	return up;
}

void quicksort(int arr[], int low, int high)
{
	if(low < high)
	{
		int q = partition(arr, low, high);
		quicksort(arr, low, q-1);
		quicksort(arr, q+1, high);
	}
}

int main()
{
	int arr[6] = {2, 4, 6, 1, 7, 8};
	for(int i=0; i<6; i++)
		cout<<arr[i]<<" ";
	
	cout<<endl;
	quicksort(arr, 0, 5);
	for(int i=0; i<6; i++)
		cout<<arr[i]<<" ";
	
	return 0;
}
