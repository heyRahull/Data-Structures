/*
A vector a of size n and an element k are given to you.You need to return the list(vector) of elements less than k. The order of elements should be the same as that in the original array.
Note: Incase, there is no element less than k then return an empty vector.

Example 1:

Input:
n = 5
vector -> 5 3 6 1 3
k = 4
Output: 
3 1 3
Explanation:
Here k is 4. Elements less than
4 in the list are {3 1 3}.


*/




#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

vector<int>getSmaller(int arr[],int n,int k)
{
vector<int>res;
for(int i=0;i<n;i++)
{
    if(arr[i]<k)
    res.push_back(arr[i]);
}
return res;
}

int main()
{
int arr[]={10,5,30,40,20};
vector<int>res = getSmaller(arr,5,25);
for(auto x:res)
cout<<x<<" ";
return 0;
}
