#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int isLargest(int arr[], int n)
{
    int max = 0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[max])
        max = i;
    }
    return max;

}

int secondLargest(int arr[], int n)
{
    int largest = isLargest(arr,n);
    int res=-1;

    for(int i=0;i<n;i++)
    {
        if(arr[i]!=arr[largest])
        {
            if(res==-1)
            res= i;
            else if(arr[i]>arr[res])
            res=i;
        }
    }
    return res;


}

int main()
{
    int arr[]={20,10,20,8,12};
    cout<<secondLargest(arr,5);
}
