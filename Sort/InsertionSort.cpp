// Insertion sort
#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector <int>& arr, int n)
{
    for(int j=1; j<n; j++)
    {
        int i =j-1;
        while(i >= 0)
        {
            if(arr[i] > arr[i+1])
            {
                swap(arr[i], arr[i+1]);
                i--;
            }
            else{
                break;
            }
        }
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
    
    insertionSort(arr, n);
    
    for(int i=0; i<n; i++)
    {
        cout<< arr[i]<< " ";
    }
    
    return 0;
}
