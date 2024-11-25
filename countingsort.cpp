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
    int count[maxvalue+1]={0};
    for(int i=0;i<n;i++)
    {
        count[arr[i]]++;
    }
    for(int i=0;i<=maxvalue;i++)
    {
        if(count[i]!=0)
        {
           for(int j=0;j<count[i];j++)
           {
             cout<<i<<" ";
           }
        }
        
    }
}