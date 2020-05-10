/*
Find K Closest Points to the Origin
Given a list of points on the 2-D plane and an integer K. The task is to find K closest points to the origin and print them.

Input : point = [[1, 3], [-2, 2], [5, 8], [0, 1]
        K = 2

Output : [[3, 3], [-2, 4]]

Explanation:
Square of Distance of origin from this point is
(1, 3) = 10
(-2, 2) = 8
(5, 8) = 89
(0, 1) = 1
So the closest two points are [-2, 2], [0, 1].

*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[4][2]={{1,3},{-2,2},{5,8},{0,1}};
    int n=4;
    int k=2;

    priority_queue<pair<int,pair<int,int> > > maxh;

    for(int i=0;i<n;i++)
    {
        maxh.push({arr[i][0]*arr[i][0]+arr[i][1]*arr[i][1],{arr[i][0],arr[i][1]}});
        if(maxh.size()>k)
            maxh.pop();
    }


    cout<<"The closest points to origin are : \n";
    while(maxh.size()>0)
    {
        pair<int,int>p=maxh.top().second;
        cout<<"["<<p.first<<" "<<p.second<<"]"<<"\n";
        maxh.pop();
    }

}
