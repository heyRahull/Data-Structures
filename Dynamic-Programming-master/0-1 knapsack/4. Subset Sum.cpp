/*
------------------------------Subset Sum ---------------------------
Subset sum problem is to find subset of elements that are selected from a given set whose sum adds up to a given number K(sum).
We are considering the set contains non-negative values.
It is assumed that the input set is unique (no duplicates are presented).

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
                t[i][j]=( t[i-1][j-arr[i-1]] || t[i-1][j]);
            else
                t[i][j]=t[i-1][j];
        }

    }
    return t[n][sum];
}

int main()
{
    int arr[]={2,3,7,8,10};
    int sum=11;
    int n=sizeof(arr)/sizeof(arr[0]);


    if(sumofsubset(arr,sum,n))//if the function returns 1 then print true which means that sum of subset is possible
        cout<<"True";
    else
        cout<<"False";
}
