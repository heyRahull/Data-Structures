#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int getLargest(int arr[],int n)
{
    int max=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[max])
        max=i;
    }
    return max;
}

int main()
{
    int arr[]={5,8,20,10};
    cout<<getLargest(arr,4);
}
