/*
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S.
Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:

Input: arr is [1, 1, 1, 1, 1],
       S is 3.
Output: 5

Explanation:

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of arr be target 3.


NOTE :- This is the same problem that is,count of no. of subset with a given difference,just the way of asking is different.
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
    int arr[]={1,1,1,1,1};
    int diff=3;
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
