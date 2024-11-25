#include<bits/stdc++.h>
using namespace std;

int maxi(int arr[],int n)
{
   int max_val=arr[0];
   for(int i=0;i<n;i++)
   {
      max_val=max(max_val,arr[i]);
   }
   return max_val;
}

void countsort(int arr[],int n,int exp)
{
    int output[n];
    int i,count[10]={0};

    for(int i=0;i<n;i++)
    {
        count[(arr[i]/exp)%10]++;
    }

    for(int i=1;i<10;i++)
    {
        count[i]+=count[i-1];
    }
     
    
    for(int i=n-1;i>=0;i--)
    {
        output[count[(arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }

    for(int i=0;i<n;i++)
    {
        arr[i]=output[i];
    }
}

void radixsort(int arr[],int n)
{
    int m=maxi(arr,n);

    for(int exp=1;m/exp>0;exp*=10)
    {
        countsort(arr,n,exp);
    }

}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    radixsort(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

}