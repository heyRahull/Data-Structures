/*
-------------------Count Number of Subset with a given Difference---------------------------

Partition a set into two subsets such that the difference of subset sums is equal to the given difference.
Given a set of integers, the task is to divide it into two sets S1 and S2 such that
the absolute difference between their sums is equal to the given difference.


Example:

Input:  arr[] = {1, 1, 2, 3}
        diff = 1
Output: 3

Explanation:
Subset1 = {1, 1, 2}, sum of Subset1 = 4
Subset2 = {3}, sum of Subset2 = 3
The difference between these two Subsets is 1.



Subset1 = {1, 3}, sum of Subset1 = 4
Subset2 = {1, 2}, sum of Subset2 = 3
The difference between these two Subsets is 1.



Subset1 = {1, 3}, sum of Subset1 = 4
Subset2 = {1, 2}, sum of Subset2 = 3
The difference between these two Subsets is 1.

So, in this way we got the count of Number of subset with a given difference as 3.


NOTE :In this problem we will use the function CountSubsetSum which we have studied already.
*/
#include<bits/stdc++.h>
using namespace std;

CountSubsetSum(int arr[],int sum,int n)
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
                t[i][j]=( t[i-1][j-arr[i-1]] + t[i-1][j]);
            else
                t[i][j]=t[i-1][j];
        }

    }
    return t[n][sum];
}
int main()
{
    int arr[]={1,1,2,3};
    int diff=1;
    int n=sizeof(arr)/sizeof(arr[0]);
    int sumofarr =0;

    for(int i=0;i<n;i++)
    {
        sumofarr = sumofarr + arr[i];
    }

    int sum = (diff + sumofarr)/2;  //we get this equation by solving
                                    //Equation 1: sumofsubset1 - sumofsubset2 = diff
                                    //Equation 2: sumofsubset1 + sumofsubset2 = sumofarr
    cout<<CountSubsetSum(arr,sum,n);

}
