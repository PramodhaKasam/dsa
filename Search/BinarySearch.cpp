//Binary Search
#include <bits/stdc++.h>
using namespace std;

void binarySearch(int arr[], int num, int low, int high)
{
	if(low<= high)
	{
		int mid = low + (high -low)/2;
	
		if(arr[mid] > num)
			binarySearch(arr, 18, low, mid -1);
			
		else if(arr[mid] < num)
			binarySearch(arr, 18, mid + 1, high);
		else{
			cout<<1;
			return;
		}
	}
	
}

int main()
{
	int arr[10];
	
	for(int i=0; i<10; i++)
		arr[i] = 2*i;
	
	binarySearch(arr, 1, 0, 10);
	return 0;
}
