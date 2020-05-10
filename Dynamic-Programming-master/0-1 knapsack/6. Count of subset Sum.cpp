/*
----------------------------Count of Subset Sum -------------------------------------------

Count of subsets with sum equal to X
Given an array arr[] of length N and an integer X, the task is to find the number of subsets with sum equal to X.

Example:

Input: arr[] = {2,3,5,6,8,10}, X = 10
Output: 3
All the possible subsets are {2, 3, 5},
{2, 8} and {10}
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
                t[i][j]=( t[i-1][j-arr[i-1]] + t[i-1][j]);
            else
                t[i][j]=t[i-1][j];
        }

    }
    return t[n][sum];
}

int main()
{
    int arr[]={2,3,5,6,8,10};
    int sum=10;
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<sumofsubset(arr,sum,n);
    /*if(sumofsubset(arr,sum,n))//if the function returns 1 then print true which means that sum of subset is possible
        cout<<"True";
    else
        cout<<"False";*/
}
