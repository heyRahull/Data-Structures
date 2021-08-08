/*
Given a vector, keep track of the present indexes corresponding to each element and after sorting print element with its previous respective indexes.

Examples:

Input: Arr[] = {2, 5, 3, 7, 1}
Output: {1, 4} {2, 0} {3, 2} {5, 1} {7, 3}
Explanation:
Before sorting [index(element)]: [0(2), 1(5), 2(3), 3(7), 4(1)]
After sorting [previous_index(element)]: [4(1), 0(2), 2(3), 1(5), 3(7)]

Input: Arr[] = {4, 5, 10, 8, 3, 11}
Output: {3, 4} {4, 0} {5, 1} {8, 3} {10, 2} {11, 5}
*/

#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

void printSortedWithIndexes(int arr[],int n){
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++)
    {
        v.push_back({arr[i],i});
    }
    sort(v.begin(),v.end());

    for(auto x:v)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }
}

int main()
{
int arr[]={20,40,30,10};
printSortedWithIndexes(arr,4);
}
