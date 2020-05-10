/*

--------------------------Find k closest elements to a given value-------------------------------
Given an array arr[] and a value X, find the k closest elements to X in arr[].
Examples:

Input: K = 3, X = 5
       arr[] = {5,3,9,1,2,1}
Output: 2 3 5
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
int arr[]={5,3,9,1,2,1};
int n =sizeof(arr)/sizeof(arr[0]);
int x=5;
int k=3;

priority_queue<pair<int,int>>maxh;//declaring a paired max heap

for(int i=0;i<n;i++)
{
    maxh.push({abs(arr[i]-x),arr[i]});  //the first part of heap the difference between the element and the current array value(the difference here acts as a key for sorting),
                                        //and the second part contains the current array value.

    if(maxh.size()>k)
        maxh.pop();

}


cout<<"\nThe "<< k <<" closest elements to "<<x <<" are : ";
while(maxh.size()>0)
{
    cout<<maxh.top().second<<" ";
    maxh.pop();

}
cout<<"\n\n";//just to make the output look nice
}
