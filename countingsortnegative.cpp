#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int maxvalue=*max_element(arr,arr+n);
    int minvalue=*min_element(arr,arr+n);
    int range=maxvalue-minvalue+1;
    int count[range]={0};
    for(int i=0;i<n;i++)
    {
        count[arr[i]-minvalue]++; // offsetting
    }
    for(int i=0;i<range;i++)
    {
        if(count[i]!=0)
        {
           for(int j=0;j<count[i];j++)
           {
             cout<<i+minvalue<<" ";
           }
        }
        
    }
}