//Heap sort
#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int i, int n)
{
	int left = 2*i + 1;
	int right = 2*i +2;
	
	int largest = i;
	
	if(left < n && arr[left] > arr[i])
		largest = left;
	
	if(right < n && arr[right] > arr[largest])
		largest = right;
		
	if(largest != i)
	{
		swap(arr[i], arr[largest]);
		heapify(arr, largest, n);
	}
}

void build_heap(int arr[], int n)
{
	for(int i = n/2 -1 ; i>= 0; i--)
		heapify(arr, i, n);	
}

void heapsort(int arr[], int n)
{
	build_heap(arr, n);
	
	for(int i= n-1; i>=0; i--)
	{
		swap(arr[i], arr[0]);
		heapify(arr, 0, i);
	}
}

int main()
{
	int arr[] = {1, 2, 8 , 6 , 5, 7};
	heapsort(arr, 6); //o(nlogn)
	for(int i=0; i<6; i++)
		cout<<arr[i]<<" ";
		
	return 0;
}
