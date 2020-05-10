/*
-----------------------------Frequency Sort----------------------------------

Print the elements of an array in the order of decreasing frequency
Examples:

Input:  arr[] = {1,1,1,3,2,2,4}
Output: arr[] = {1,1,1,2,2,4,3}

*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={1,1,1,3,2,2,4};
    int n=sizeof(arr)/sizeof(arr[0]);

    priority_queue<pair<int,int>>maxh;
    unordered_map<int,int>mp;;


    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }

    for(auto i=mp.begin();i !=mp.end();i++)
    {
      maxh.push({i->second,i->first});


    }


    cout<<"The sorted array according to frequency is : ";
    while(maxh.size()>0)
    {
       int freq=maxh.top().first;
       int ele=maxh.top().second;
       for(int i=0;i<freq;i++)
        cout<<ele<<" ";

       maxh.pop();
    }
}
