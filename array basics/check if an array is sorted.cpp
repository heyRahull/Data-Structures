//Efficient approach - O(N)
#include<iostream>
#include<string>
using namespace std;
bool isSorted(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    if(arr[i]>arr[i+1])
    return false;
   return true;
}
int main()
{
    int arr[]={100,30,200};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    if(isSorted(arr,n))
    cout<<"Array is Sorted";
    else
    cout<<"Array is not sorted";
}
