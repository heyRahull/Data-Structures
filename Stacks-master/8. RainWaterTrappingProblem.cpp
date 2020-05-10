/*Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it is able to trap after raining.

Input: arr[]   = {3, 0, 0, 2, 0, 4}
Output: 10
Structure is like below
     |
|    |
|  | |
|__|_|
We can trap "3*2 units" of water between 3 an 2,
"1 unit" on top of bar 2 and "3 units" between 2
and 4.  See below diagram also.



//We have make use of array ,if wanted we can also perform it by using stack (since our program also takes O(n) complexity and is easier to understand so i have written this.

*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={3,0,0,2,0,4};

    int n=sizeof(arr)/sizeof(arr[0]);
    int mxl[n];
    int mxr[n];

    mxl[0]=arr[0];
    for(int i=1;i<n;i++){
        mxl[i]= max(mxl[i-1],arr[i]);

    }

    mxr[n-1]=arr[n-1];

    for(int i=n-2;i>=0;i--){
        mxr[i]=max(mxr[i+1],arr[i]);
    }

    int water[n];
    for(int i=0;i<n;i++){
        water[i]=min(mxl[i],mxr[i])-arr[i];
    }

    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+water[i];
    }
    cout<<"Maximum Water trapped is :"<<sum;
}
