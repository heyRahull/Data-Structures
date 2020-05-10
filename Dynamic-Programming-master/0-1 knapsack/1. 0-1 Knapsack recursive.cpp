/*
     ----------------Recursive Knapsack-------------------------

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

int knapsack(int wt[],int val[],int w,int n)
{
    if(n==0||w==0) //if there is no item left to be added in the knapsack or if the weight of the knapsack becomes 0
    {
        return 0;
    }

    if(wt[n-1]<=w)//if the weight of the item is less than the weight of the knapsack
    {
        return max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1));
    }

    if(wt[n-1]>w)//if the weight of the item is greater than the weight of the knapsack then we can't add this item in the knapsack
    {
        return knapsack(wt,val,w,n-1);//so call knapsack function for the remaining items
    }

}

int main()
{
    int wt[]= {1,3,4,5};
    int val[]={1,4,5,2};
    int w=7;
    int n= sizeof(wt)/sizeof(wt[0]);

    cout<<"The maximum profit will be :";
    cout<<knapsack(wt,val,w,n-1);

}
