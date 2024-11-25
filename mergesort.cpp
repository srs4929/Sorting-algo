#include<bits/stdc++.h>
using namespace std;


void mergesort(int arr[],int n,int s,int e)
{
   
    int mid=(s+e)/2;
    int k=s;//main array index
    int len1=(mid-s+1);
    int len2=(e-mid);
    int first[len1];
    int second[len2];
    
    //copying the elements
    for(int i=0;i<len1;i++)
    {
       first[i]=arr[k++];
    }
    k=mid+1;
    for(int i=0;i<len2;i++)
    {
        second[i]=arr[k++];
    }
    //merge two arary

    int index1=0;
    int index2=0;
    int j=s;//main array index
    while(index1<len1&&index2<len2)
    {
          if(first[index1]<second[index2]) 
          {
             arr[j++]=first[index1];
             index1++;
          }
          else
          {
            arr[j++]=second[index2];
            index2++;
          }
    }
    //left out elements
    while(index1<len1)
    {
        arr[j++]=first[index1++];
    }
    while(index2<len2)
    {
        arr[j++]=second[index2++];
    }

}

void merge(int arr[],int n,int s,int e)
{
    if(s>=e) return;
    int mid=(s+e)/2;
    //left array sorted
    merge(arr,n,s,mid);
    //right array sorted
    merge(arr,n,mid+1,e);
    //full arary sorted merged
    mergesort(arr,n,s,e);
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
    merge(arr,n,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}