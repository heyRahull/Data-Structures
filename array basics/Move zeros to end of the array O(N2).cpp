#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void moveZero(int arr[], int n)
{
 for(int i=0;i<n;i++)
 {
    if(arr[i]==0)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]!=0)
            {
            swap(arr[i],arr[j]);
            break;
            }
        }

    }
    for(int i=0;i<n;i++)
 cout<<arr[i]<<" ";
 cout<<endl;
 }

 
}

int main()
{
    int arr[]={8,5,0,10,0,20};
    moveZero(arr,6);
}
