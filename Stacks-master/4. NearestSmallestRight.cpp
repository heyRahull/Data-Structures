/* NEAREST SMALLEST RIGHT
Given an array, print the Next Smallest Element (NSE) for every element.
The Next Smaller Element for an element x is the first smaller element on the Right side of x in array.
Elements for which no smaller element exist, consider next smaller element as -1.
Examples:
1.For any array, rightmost element always has next smaller element as -1.
2.For an array which is sorted in decreasing order, all elements have next smaller element as -1.
3.For the input array [4, 5, 2, 25], the next smaller elements for each element are as follows.

 Element       NGE
   4      -->   2
   5      -->   2
   2      -->   -1
   10     -->   8
   8      -->   -1
 */



#include<bits/stdc++.h>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    int arr[]={4,5,2,10,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    stack<int>s;
    vector<int>v;

    for(int i=n-1;i>=0;i--)
    {
        if(s.size()==0)   //if the stack is empty
            v.push_back(-1);
        else if(s.size()>0 && s.top()<arr[i])  //if the value in the top of the stack is lesser than the current value of array
            v.push_back(s.top());
        else if(s.size()>0 && s.top()>=arr[i] ) //if the value in the top of the stack is larger than the current value of array
        {
            while(s.size()>0 && s.top()>=arr[i])
                s.pop();                         //keep on popping the elements of stack until either the stack gets empty or the top of the stack
                                                //becomes lesser than the current value of array.


        if(s.size()==0)
            v.push_back(-1);
        else
            v.push_back(s.top());
        }

        s.push(arr[i]);
    }

    reverse(v.begin(),v.end());  //We are reversing the value of Vector.
    for(int i=0;i<n;i++)
    {

        cout<<arr[i]<<"-->"<<v[i]<<"\n";
    }

}
