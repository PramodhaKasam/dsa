// Insertion sort
#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector <int>& arr, int n)
{
    for(int i=1; i<n; i++)
    {
        int j =i-1;
        int key = arr[i];
        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main()
{
    int n;
    cin>>n;
    vector <int> arr(n);
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    
    cout<<"Given input: ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    insertionSort(arr, n);  // O(n^2)
    cout<<"\nAfter sorting: ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
