// Merge sort
#include <bits/stdc++.h>
using namespace std;

void merge(vector <int>& arr, int left, int mid, int right)
{
    int n1 = mid-left+1;
    int n2 = right-mid;
    vector <int> l(n1);
    vector <int> r(n2);
    for(int i=0; i<n1; i++)
    {
        l[i] = arr[i+ left];
    }
    
    for(int i=0; i<n2; i++)
    {
        r[i] = arr[i+ mid+1];
    }
    int j=0, k=0, i= left;
    while(j< n1 && k < n2)
    {
        if(l[j] <= r[k])
        {
            arr[i] = l[j];
            j++;
        }
        else{
            arr[i] = r[k];
            k++;
        }
        i++;
    }
    
    while(j < n1)
    {
        arr[i] = l[j];
        i++;
        j++;
    }
    
     while(k < n2)
    {
        arr[i] = r[k];
        i++;
        k++;
    }
    
}

void mergeSort(vector <int>& arr, int left, int right)
{
    if(left >= right)
        return;
    else{
        int mid = left + (right - left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
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
    
    mergeSort(arr, 0, n-1);  // O(nlogn)
    cout<<"\nAfter sorting: ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
