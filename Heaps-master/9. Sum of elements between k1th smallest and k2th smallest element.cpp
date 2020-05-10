/*
-----------------------Sum of all elements between k1’th and k2’th smallest elements----------------------

Given an array of integers and two numbers k1 and k2.
Find the sum of all elements between given two k1’th and k2’th smallest elements of the array.
It may be assumed that (1 <= k1 < k2 <= n) and all elements of array are distinct.
Examples :

Input : arr[] = {20, 8, 22, 4, 12, 10, 14},  k1 = 3,  k2 = 6
Output : 26
         3rd smallest element is 10. 6th smallest element
         is 20. Sum of all element between k1 & k2 is
         12 + 14 = 26

Input : arr[] = {1,3,12,5,15,11}, k1 = 3, k2 = 6
Output : 23

*/
#include<bits/stdc++.h>
using namespace std;

kth_smallest(int arr[],int k,int n)//this function returns the kth smallest number
{
       priority_queue<int> maxh;
    for(int i=0;i<n;i++)
    {
        maxh.push(arr[i]);
        if(maxh.size()>k)
            maxh.pop();

    }
    return maxh.top();
}

int main()
{

    int arr[]={1,3,12,5,15,11};   //given array
    int n=sizeof(arr)/sizeof(arr[0]);//size of the array
    int k1=3;
    int k2=6;

    int first=kth_smallest(arr,k1,n); //variable first contains the k1th smallest element
    int second=kth_smallest(arr,k2,n); //variable second contains the k2th smallest element
    int sum=0;


    for(int i=0;i<n;i++)
    {
        if(arr[i]>first && arr[i]<second)
            sum=sum+arr[i];  //variable sum contains the sum of elements between k1th and k2th elements
    }
    cout<<"The sum of the elements between "<<k1<<"th element and "<<k2<<"th element is : "<<sum;
}
