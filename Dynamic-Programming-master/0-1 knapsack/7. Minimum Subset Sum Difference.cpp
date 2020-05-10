/*
-------------------Minimum Subset Sum Difference---------------------------
Partition a set into two subsets such that the difference of subset sums is minimum
Given a set of integers, the task is to divide it into two sets S1 and S2 such that
the absolute difference between their sums is minimum.
If there is a set S with n elements, then if we assume Subset1 has m elements,
Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.

Example:




Input:  arr[] = {1, 6, 11, 5}
Output: 1
Explanation:
Subset1 = {1, 5, 6}, sum of Subset1 = 12
Subset2 = {11}, sum of Subset2 = 11

The difference between these two Subsets is 1.
*/
#include<bits/stdc++.h>
using namespace std;

vector<int>v;

sumofsubset(int arr[],int sum,int n)
{

    int t[n+1][sum+1];
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

    for(int j=0;j<=ceil(sum/2);j++)//this for loop is for pushing half of the last line of matrix into the vector
    {
        if(t[3][j]==true)//push only those sum values which lies in the range 0 to sum.
            v.push_back(j);
    }
    //return t[n][sum];
}

int main()
{
    int arr[]={1,6,11,5};
    float sum=0;
    int n=sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n;i++)//this for loop will find the sum of the entire array
    {
        sum=sum +arr[i];
    }

sumofsubset(arr,sum,n);

    float mn=sum;//assigning the largest difference(which is sum-0) to variable mn.
    for(int i=0;i<v.size();i++)
    {
        mn=min(mn,sum-2*v[i]);//finding minimum of all the subset sum differences
        cout<<v[i]<<" "; //printing the vector elements
    }

    cout<<"\n"<<mn;//printing the minimum subset sum difference

}
