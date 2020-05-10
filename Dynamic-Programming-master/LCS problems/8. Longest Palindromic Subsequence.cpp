/*
---------------------LONGEST PALINDROMIC SUBSEQUENCE USING DP---------------------

The Longest Palindromic Subsequence Problem(LPS) is the problem of finding the longest subseqences
of a string that is also a palindrome.

The problem differs from the problem of finding common substrings.Unlike substrings,subsequences are
not required to occupy consecutive positions within the original sequences.

For example,consider the sequence ABBDCACB

The Length of Longest Palindromic Subsequence is 5.
The Longest Palindromic Subsequence is BCACB.


Explanation :
The idea is that we are given a string x,we will find the reverse of that string and store it in string y.
Then we find the longest common subsequence int the strings x and y.
And the LCS in this case will only be the Longest Palindromic subsequence.
*/
#include<bits/stdc++.h>
using namespace std;


LCS(string x,string y,int m,int n)
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
                t[i][j]=max(t[i][j-1],t[i-1][j]);

        }
    }
    return t[m][n];

}

int main()
{
    string x="agbcba";
    string y=x;
    reverse(y.begin(),y.end());
    int m=x.length();
    int n=y.length();

    cout<<"The length of Longest Palindromic subsequence is : ";
    cout<<LCS(x,y,m,n);
}
