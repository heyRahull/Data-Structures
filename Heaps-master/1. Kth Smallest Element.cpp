/*------------------K’th smallest Element -------------------------

Given an array of size n, find the kth least element in the array.
Example:

Input : {7,10,4,3,20,15}
k = 3
Output : 7
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{

    int arr[]={7,10,4,3,20,15};
    int k=3;
    int n =sizeof(arr)/sizeof(arr[0]);

    priority_queue<int> maxh;
    for(int i=0;i<n;i++)
    {
        maxh.push(arr[i]);
        if(maxh.size()>k)
            maxh.pop();

    }
    cout<<k<<"th smallest element is :"<<maxh.top();
}
