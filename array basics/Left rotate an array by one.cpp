#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void leftRotate(int arr[], int n)
{
    int temp = arr[0];
    for(int i=0;i<n-1;i++)
    arr[i] = arr[i+1];    

arr[n-1] = temp;

for(int i=0;i<n;i++)
cout<<arr[i]<<" ";
}

int main()
{
    int arr[]={10,20,30,40,50};
    leftRotate(arr,4);
}
