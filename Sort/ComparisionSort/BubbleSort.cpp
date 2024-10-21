// Bubble sort
#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector <int>& arr, int n)
{
    int count =1;
    while(count)
    {
        count = 0;
        for(int i=1; i<n; i++)
        {
            if(arr[i-1]> arr[i])
            {
                swap(arr[i], arr[i-1]);
                count++;
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
    
    cout<<"Given input: ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    bubbleSort(arr, n);  // O(n^2)
    cout<<"\nAfter sorting: ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
