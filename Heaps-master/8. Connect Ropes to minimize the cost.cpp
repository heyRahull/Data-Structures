/*

Connect n ropes with minimum cost

There are given n ropes of different lengths,
we need to connect these ropes into one rope.
The cost to connect two ropes is equal to sum of their lengths.
We need to connect all the ropes such that the total cost will be minimum.

For example if we are given 5 ropes of lengths 1, 2, 3, 4 and 5. We can connect the ropes in following ways.
1) First connect ropes of lengths 1 and 2. Now we have four ropes of lengths 3, 3, 4 and 5.
2) Now connect ropes of lengths 3 and 3. Now we have three ropes of lengths 6, 4 and 5.
3) Now connect ropes of lengths 4 and 5. Now we have two ropes of lengths 6 and 9.
4) Finally connect the two ropes of length 6 and 9 ,and now all ropes have connected.

Total cost for connecting all ropes is 3 + 6 + 15 + 9 = 33.This is the optimized cost for connecting ropes.
Other ways of connecting ropes would always have same or more cost.
For example, if we connect 1 and 2 first (we get four strings of 3, 3, 4 and 5),
then connect 3 and 3 (we get three strings of 6, 4 and 5),
then connect 6 and 4 (we get two strings of 10 and 5).
Finally we connect 10 and 5. Total cost in this way is 3 + 6 + 10+ 15= 34(which is not optimal or minimum).


*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);

    priority_queue<int,vector<int>,greater<int> >minh;
    int cost=0;
    for(int i=0;i<n;i++)
    {
        minh.push(arr[i]); //pushing all the elements of stack in array

    }

    while(minh.size()>=2)
    {
        int first=minh.top();  //storing the top element in first variable
        minh.pop();            //pop the top element
        int second=minh.top(); //storing the top element in second variable
        minh.pop();            //pop the top element
        cost=cost+first+second;//calculating the cost of adding the ropes
        minh.push(first+second);//pushing back the joined rope into the minheap
    }
    cout<<cost;//printing the minimized cost
}
