//Counting sort
#include <bits/stdc++.h>
using namespace std;

vector <int> countSort(vector <int>& arr, int n)
{
    int maxi =0;
    for(int i=0; i<n; i++)
        maxi = max(maxi, arr[i]);
    
    vector <int> count(maxi+1, 0);
    for(int i=0; i<n;i++)
        count[arr[i]]++;
    
    for(int i=1; i<maxi+1; i++)
        count[i] += count[i-1];
    
    vector <int> out(n);
    for(int i=n-1; i>=0; i--)
    {
        out[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }
    return out;
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
    vector <int> ans;
    ans = countSort(arr, n); // O(n+m)
    cout<<"\nAfter sorting: ";
    for(int i=0; i<n; i++)
    {
        cout<<ans[i]<<" ";
    }
    
    return 0;
}
