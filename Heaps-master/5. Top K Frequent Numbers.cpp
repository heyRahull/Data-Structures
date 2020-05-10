/*
Find k numbers with most occurrences in the given array
Given an array of n numbers and a positive integer k. The problem is to find k numbers with most occurrences,
i.e., the top k numbers having the maximum frequency.

Input:
arr[] = {1,1,1,3,2,2,4},
k = 2
Output: 2 1
Explanation:

Frequency of 2 = 2
Frequency of 1 = 3
These two have the maximum frequency
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={1,1,1,3,2,2,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=2;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minh;
    unordered_map<int,int>mp;  //creating an unordered map(hash table which contains no. of times a digit is occurring in an array  or the frequency of the digits of an array)

    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;

    }

    for(auto i=mp.begin();i != mp.end();i++)
    {
        minh.push({i->second,i->first});
        if(minh.size()>k)
            minh.pop();
    }


    cout<<" The "<<k<<" most frequent numbers in the given array are : ";
    while(minh.size()>0)
    {
        cout<<minh.top().second<<" ";
        minh.pop();

    }
}
