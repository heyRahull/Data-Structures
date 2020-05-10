/*
     ----------------Knapsack using Memoization Approach-------------------------

input :
            wt[] : {1,3,4,5}
            val[]: {1,4,5,2}
            w=7
            n=4

output :
            The maximum profit will be :9



*/

#include<bits/stdc++.h>
using namespace std;

int t[5][8];

int knapsack(int wt[],int val[],int w,int n)
{
    if(n==0||w==0)
        return 0;

    if(t[n][w]!=-1)
        return t[n][w];

    if(wt[n-1]<=w)
        return t[n][w]=max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1));

    else if(wt[n-1]>w)
        return t[n][w]=knapsack(wt,val,w,n-1);
}

int main()
{

    int wt[]= {1,3,4,5};
    int val[]={1,4,5,2};
    int w=7;
    int n= sizeof(wt)/sizeof(wt[0]);

    memset(t,-1,sizeof(t));

    cout<<"The maximum profit will be :";
    cout<<knapsack(wt,val,w,n);
}
