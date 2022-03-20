#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void moveZero(int arr[], int n)
{
 int count =0;
 for(int i=0;i<n;i++)
 {
     if(arr[i]!=0)
     {
         swap(arr[i],arr[count]);
         count++;
     }  
 }

for(int i=0;i<n;i++)
cout<<arr[i]<<" ";
 
}

int main()
{
    int arr[]={8,5,0,10,0,20};
    moveZero(arr,6);
}
