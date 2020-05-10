/*
-------------------------equal sum sets of array (Partition problem)--------------------------
Given an array arr[].
Determine whether it is possible to split the array into two sets
such that the sum of elements in both the sets is equal.
If it is possible, then print true. If it is not possible then output false.

Examples :


Input : arr = {5, 5, 1, 11}
Output : equal sum partition is possible
*/
#include<bits/stdc++.h>
using namespace std;

int t[6][12];
sumofsubset(int arr[],int sum,int n)
{
    for(int i=0;i<n+1;i++)//this for loop is for the base3 condition
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)
                t[i][j]=false;
            if(j==0)
                t[i][j]=true;
        }

    }


    for(int i=1;i<n+1;i++)//this for loop is for the choice diagram
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
                t[i][j]=(t[i-1][j-arr[i-1]] || t[i-1][j]);
            else
                t[i][j]=t[i-1][j];
        }

    }
     return t[n][sum];
}

int main()
{
    int arr[]={1,5,11,5};
    int sum=0;
    int n=sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n;i++)
        sum=sum+arr[i];

    if(sum%2!=0)
        cout<<" It is not possible to partition the array";
    else
        cout<<sumofsubset(arr,sum/2,n);


    if(sumofsubset(arr,sum,n))//if the function returns 1 then print true which means that sum of subset is possible
        cout<<"\nEqual sum partition is possible";
    else
        cout<<"Equal sum partition is not possible";
}
