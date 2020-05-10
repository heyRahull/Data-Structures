/*
-----------------------------------k largest elements in an array------------------------ | added Min Heap method

Question: Write an efficient program for printing k largest elements in an array.
Elements in array can be in any order.

For example, if given array is [7,10,4,3,20,15] and
you are asked for the largest 3 elements i.e., k = 3
then your program should print 10, 15 and 20.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={7,10,4,3,20,15};
    int k=3;
    int n =sizeof(arr)/sizeof(arr[0]);

    priority_queue<int,vector<int>,greater<int>> minh;


    cout<<"arr[] = ";
    for(int i=0;i<n;i++)
    {

    cout<<arr[i]<<" ";
        minh.push(arr[i]);   //pushing the largest elements in min heap
        if(minh.size()>k)
            minh.pop();

    }

    cout<<"\nThe "<<k<<" Largest Elements are :\n";
    while(minh.size()>0)  //printing the 3 largest numbers from min heap
    {

        cout<<minh.top()<<"\n";
        minh.pop();
    }
}
