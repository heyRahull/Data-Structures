#include<bits/stdc++.h>
using namespace std;

int t[6][6];
bool ispalindrome(string s,int i,int j)
{
    if(i==j)
        return true;
    if(i>j)
        return true;
    while(i<j)
    {
        if(s[i]!=s[j])
        return false;

     i++;
     j--;
    }
return true;
}


int solve(string s,int i,int j)
{
    if(i>=j)
        return 0;

    if(ispalindrome(s,i,j)==true)
        return 0;

    int mn=INT_MAX;

    if(t[i][j]!=-1)
        return t[i][j];

    for(int k=i;k<=j-1;k++)
    {
        int left;
        int right;


        //Memoization optimized code
        if(t[i][k]!=-1)
            left=t[i][k];
        else
            left=solve(s,i,k);
            t[i][k]=left;

        if(t[k+1][j]!=-1)
            right=t[k+1][j];
        else
            right=solve(s,k+1,j);
            t[k+1][j]=right;


        int temp =1+left+right;





       // int temp=1+solve(s,i,k)+solve(s,k+1,j);

        if(temp<mn)
            mn=temp;
    }
    return t[i][j]=mn;
}



int main()
{
    string s="nitik";
    int i=0;
    int j=s.length()-1;
    memset(t,-1,sizeof(t));
    cout<<" The Number of partitions required are : ";
    cout<<solve(s,i,j);
}
