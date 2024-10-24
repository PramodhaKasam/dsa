// Radix sort
#include <bits/stdc++.h>
using namespace std;

void countSort(vector <int>& arr, int n, int exp)
{
    vector <int> output(n);
    vector <int> count(10, 0);
    
    for(int i=0; i<n; i++)
    {
        count[(arr[i]/exp)%10]++;
    }
    
    for(int i=1; i<10; i++)
    {
        count[i] += count[i-1];
    }
    
    for(int i=n-1; i>=0; i--)
    {
        output[count[(arr[i]/exp)%10]- 1] = arr[i];
        count[(arr[i]/exp)%10 ]--;
    }

    for(int i=0; i<n; i++)
    {
        arr[i] = output[i];
    }
}

void radixSort(vector <int>& arr, int n)
{
    int maxi = 0;
    
    for(int i=0; i<n; i++)
    {
        maxi = max(maxi, arr[i]);
    }
    
    for(int exp =1; maxi/exp >0; exp *= 10)
    {
        countSort(arr, n, exp);
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
    radixSort(arr, n); //O(d*(b+n))
    cout<<"\nAfter sorting: ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;  
}
