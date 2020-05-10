/*
--------------------------Longest Repeating Subsequence---------------------------
Given a string, find length of the longest repeating subseequence such that the two subsequence
don’t have same string character at same position, i.e., any i’th character in the two subsequences
shouldn’t have the same index in the original string.


Input: str = "aabebcdd"
Output: 3
(The longest repeating subsequence is "abd")

Input: str = "abc"
Output: 0
There is no repeating subsequence

Input: str = "aab"
Output: 1
The two subssequence are 'a'(first) and 'a'(second).
Note that 'b' cannot be considered as part of subsequence
as it would be at same index in both.

Input: str = "aabb"
Output: 2

Input: str = "axxxy"
Output: 2
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
            if(x[i-1]==y[j-1] && i!=j)
                t[i][j]=1+t[i-1][j-1];
            else
            t[i][j]=max(t[i-1][j],t[i][j-1]);
        }
    }


    return t[m][n];
}

int main()
{
    string x="aabebcdd";
    string y=x;
    int m=x.length();
    int n=y.length();


    cout<<"The length of longest repeating subsequence is : "<<LCS_tabulation(x,y,m,n);
}
