// Selection sort
#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector <int>& arr, int n)
{
    for(int i=0; i<n; i++)
    {
        int min = i;
        
        for(int j=i+1; j<n; j++)
        {
            if(arr[j]< arr[min])
                min = j;
        }
        swap(arr[i], arr[min]);
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
    
    selectionSort(arr, n);  // O(n^2)
    cout<<"\nAfter sorting: ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
