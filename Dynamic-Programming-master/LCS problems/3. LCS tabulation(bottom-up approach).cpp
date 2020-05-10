/*
Longest Common Subsequence | DP using Tabulation

LCS Problem Statement: Given two sequences, find the length of longest subsequence present in both of them.
A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.
For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”.
Therefore,the longest subsequence is "acefg" with a length 5.So, we need 5 in the output.


Examples:
LCS for input Sequences "abcdgh" and "abedfhr" is “abdh” of length 4.
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.

Input:

string x="abcdgh"
string y="abedfhr"

output:
4

*/
#include<bits/stdc++.h>
using namespace std;

int LCS_tabulation(string x,string y,int m,int n)
{
    int t[m+1][n+1];
    for(int i=0;i<m+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(i==0||j==0)
                t[i][j]=0;
        }

    }

    for(int i=1;i<m+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(x[i-1]==y[j-1])
                t[i][j]=1+t[i-1][j-1];
            else
            t[i][j]=max(t[i-1][j],t[i][j-1]);
        }
    }

    cout<<"The length of Longest Common Subsequence is :";
    return t[m][n];
}

int main()
{
    string x="abcdgh";
    string y="abedfhr";
    int m=x.length();
    int n=y.length();


    cout<<LCS_tabulation(x,y,m,n);
}
