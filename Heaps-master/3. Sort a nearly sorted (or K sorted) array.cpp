/*
-------------------------------------Sort a nearly sorted (or K sorted) array--------------------------------
Given an array of n elements, where each element is at most k away from its target position,
devise an algorithm that sorts in O(n log k) time.

For example, let us consider k is 2, an element at index 7 in the sorted array, can be at indexes 5, 6, 7, 8, 9 in the given array.

Examples:

Input : arr[] = {6, 5, 3, 2, 8, 10, 9}
            k = 3
Output : arr[] = {2, 3, 5, 6, 8, 9, 10}

*/
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main()
{
    int arr[] = {6,5,3,2,8,10,9};
    int k=3;
    int n=sizeof(arr)/sizeof(arr[0]);

    priority_queue<int,vector<int>,greater<int>> minh;
    vector<int>v;

cout<<"arr[] :";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
       minh.push(arr[i]);
        if(minh.size()>k)
           {v.push_back(minh.top());

            minh.pop();
           }
    }

    while(minh.size()>0)
    {
        v.push_back(minh.top());
        minh.pop();
    }


    cout<<"\nThe sorted array is : ";
        for(int i=0;i<n;i++)
        {

            cout<<v[i]<<" ";
        }
}
