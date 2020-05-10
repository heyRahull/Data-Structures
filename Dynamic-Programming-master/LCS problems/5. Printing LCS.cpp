/*
------------------------Printing Longest Common Subsequence-----------------------------------
Given two sequences, print the longest subsequence present in both of them.
Examples:
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
LCS for input Sequences "acbcf" and "abcdaf" is "abcf" of length 4.

*/
#include<bits/stdc++.h>
using namespace std;

int t[6][7];
LCS(string x,string y,int m,int n)
{


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
                t[i][j]=max(t[i][j-1],t[i-1][j]);

        }
    }
    return t[m][n];

}

int main()
{
    string x="acbcf";
    string y="abcdaf";
    int m=x.length();
    int n=y.length();

    LCS(x,y,m,n);

    int i=m;
    int j=n;
    string s;
    while(i>0&&j>0)
    {
        if(x[i-1]==y[j-1])
        {
            s.push_back(x[i-1]);
            i--;
            j--;
        }
        else
        {
            if(t[i-1][j]>t[i][j-1])
                i--;
            else
                j--;
        }
    }

    reverse(s.begin(),s.end());
    cout<<"The Longest Common Subsequence is : "<<s;
}
