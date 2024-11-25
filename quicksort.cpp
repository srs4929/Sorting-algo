#include<bits/stdc++.h>
using namespace std;

int pivot(int arr[],int s,int e)
{
     int pivot=arr[s];
     int cnt=0;

     for(int i=s+1;i<e;i++)
     {
         if(arr[i]<=pivot)
         cnt++;
     }
     
     //place pivot at right position
     int pivotindex=s+cnt; 

     swap(arr[pivotindex],arr[s]);

     int i=s,j=e;
     while(i<pivotindex&&j<pivotindex)
     {
           while(arr[i]<pivot)
           {
            i++;
           }
           while(arr[j]>pivot)
           {
            j--;
           }
           if(i<pivotindex&&j<pivotindex)
           {
                swap(arr[i++],arr[j--]);
           }
     }
     return pivot;
}

void quicksort(int arr[],int s,int e)
{
    if(s>=e) return;
    //finding the right pivot and right index
    int p=pivot(arr,s,e);
    //right part sort
    quicksort(arr,s,p-1);
    //left part sort
    quicksort(arr,p+1,e);

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
    quicksort(arr,0,n);
    for(int i=0;i<n;i++)
   {
      cout<<arr[i] <<"";
   }
}