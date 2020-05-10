/*
Longest Common Subsequence | DP using Memoization
Given two strings s1 and s2, the task is to find the length of longest common subsequence present in both of them.

Examples:

Input: s1 = "abcdgh", s2 = "abedfhr"
Output: 4
LCS for input Sequences "abcdgh" and "abedfhr" is "abdh" of length 4.


*/
#include<bits/stdc++.h>
using namespace std;

 int t[7][8];
LCS_Memoization(string x,string y,int m,int n)
{

     if(m==0||n==0)
     return 0;

    if(t[m][n]!=-1)//if the value in the table cell is something other than -1,then return that value
     return t[m][n];


     if(x[m-1]==y[n-1])
        return t[m][n]=1+LCS_Memoization(x,y,m-1,n-1);
      else
         return t[m][n]=max(LCS_Memoization(x,y,m-1,n),LCS_Memoization(x,y,m,n-1));



}

int main()
{
    string x="abcdgh";
    string y="abedfhr";
    int m=x.length();
    int n=y.length();

    memset(t,-1,sizeof(t));

    cout<<"The length of Longest Common Subsequence is :";
    cout<<LCS_Memoization(x,y,m,n);

}
