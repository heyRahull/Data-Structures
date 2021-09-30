//largest element in array
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int arr[]={40,8,50,100};
    int n = sizeof(arr)/sizeof(arr[0]);
    int res = 0;

    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[res])
        res = i;
    }
    cout<<res;
   

}
