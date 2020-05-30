#include<bits/stdc++.h>
using namespace std;

int t[3][7];
int solve(int e,int f)
{

    if(f==0||f==1)
        return f;

    if(e==1)
        return f;

    int mn=INT_MAX;

    if(t[e][f]!=-1)
        return t[e][f];

    for(int k=1;k<=f;k++)
    {
        int temp=1+max(solve(e-1,k-1),solve(e,f-k));

        mn=min(mn,temp);
    }
    return t[e][f]=mn;
}

int main()
{

    int f=6;//number of floors
    int e=2;//number of eggs

    memset(t,-1,sizeof(t));
    cout<<solve(e,f);
}
