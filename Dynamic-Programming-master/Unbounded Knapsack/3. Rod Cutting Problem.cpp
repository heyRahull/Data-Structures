/*
Cutting a Rod | DP-13
Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n.
Determine the maximum value obtainable by cutting up the rod and selling the pieces.
For example, if length of the rod is 8 and the values of different pieces are given as following,
then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)

Input:

length[] : { 1   2   3   4   5   6   7   8 }
price[] : { 1   5   8   9  10  17  17  20}
N : 8

Output:
22

NOTE : This is the same code of Unbounded knapsack using 2-d array we have just changed the
name of wt[] to length[]
        val[] to price[]
        w to N.
*/
#include<bits/stdc++.h>
using namespace std;

int RodCutting(int length[],int price[],int N,int n)
{
    int t[n+1][N+1];

    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<N+1;j++)
        {
            if(i==0||j==0)
                t[i][j]=0;

        }

    }


    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<N+1;j++)
        {
            if(length[i-1]<=j)
            {
                t[i][j]=max(price[i-1]+t[i][j-length[i-1]],t[i-1][j]);
            }
            else
                t[i][j]=t[i-1][j];
        }

    }
    return t[n][N];

}

int main()
{
    int length[]={1,2,3,4,5,6,7,8};
    int price[]={1,5,8,9,10,17,17,20};
    int N=8;
    int n=sizeof(length)/sizeof(length[0]);


    cout<<"The maximum profit obtained after cutting the rod is :";
    cout<<RodCutting(length,price,N,n);

}
