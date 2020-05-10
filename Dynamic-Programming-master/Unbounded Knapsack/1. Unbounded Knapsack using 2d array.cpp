/*
----------------------------Unbounded Knapsack (Repetition of items allowed)--------------------------------------
Given a knapsack weight w and a set of n items with certain value val[] and weight wt[],
we need to calculate minimum amount that could make up this quantity exactly.
This is different from classical Knapsack problem, here we are allowed to use unlimited number of instances of an item.

Example 1:

Input : W = 100
       val[]  = {1, 30}
       wt[] = {1, 50}
Output : 100
There are many ways to fill knapsack.
1) 2 instances of 50 unit weight item.
2) 100 instances of 1 unit weight item.
3) 1 instance of 50 unit weight item and 50
   instances of 1 unit weight items.
We get maximum value with option 2.


Example 2:
Input : W = 8
       val[] = {10, 40, 50, 70}
       wt[]  = {1, 3, 4, 5}
Output : 110
We get maximum value with one unit of
weight 5 and one unit of weight 3.
*/
#include<bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int wt[],int val[],int w,int n)
{
    int t[n+1][w+1];

    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<w+1;j++)
        {
            if(i==0||j==0)
                t[i][j]=0;

        }

    }


    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<w+1;j++)
        {
            if(wt[i-1]<=j)
            {
                t[i][j]=max(val[i-1]+t[i][j-wt[i-1]],t[i-1][j]);
            }
            else
                t[i][j]=t[i-1][j];
        }

    }
    return t[n][w];

}

int main()
{
    int wt[]={1,3,4,5};
    int val[]={10,40,50,70};
    int w=8;
    int n=sizeof(wt)/sizeof(wt[0]);


    cout<<"The maximum profit using unbounded knapsack is :";
    cout<<unboundedKnapsack(wt,val,w,n);

}
