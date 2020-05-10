/*

   ----------------Knapsack using Tabulation Approach-------------------------

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

int t[4][8]; //declaring a matrix which will contain the value

int knapsack(int wt[],int val[],int w,int n)
{
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<w+1;j++)
        {
            if(i==0||j==0) //if there is no item left to be added in the knapsack or if the weight of the knapsack becomes 0
                t[i][j]==0;//then initialize that cell of the matrix to 0
        }
    }

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<w+1;j++)
        {
            if(wt[i-1]<=j)//if the weight of the item is less than the weight of the knapsack
                t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);

            else if(wt[i-1]>j)//if the weight of the item is greater than the weight of the knapsack then we can't add this item in the knapsack
                t[i][j]=t[i-1][j];//store the value of the previous cell into the current cell
        }

    }
    return t[n][w];
}

int main()
{
     int wt[]= {1,3,4,5};
    int val[]={1,4,5,2};
    int w=7;
    int n= sizeof(wt)/sizeof(wt[0]);


    cout<<"The maximum profit will be :";
    cout<<knapsack(wt,val,w,n);
}
