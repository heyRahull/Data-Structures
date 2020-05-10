/*
Longest Common Subsequence | DP

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

LCS_recursive(string x,string y,int n,int m)
{
    if(n==0||m==0)
        return 0;
    if(x[n-1]==y[n-1])
    return 1+LCS_recursive(x,y,n-1,m-1);
    else
        return max(LCS_recursive(x,y,n,m-1),LCS_recursive(x,y,n-1,m));
}

int main()
{
     string x="abcdgh";
     string y="abedfhr";
    int n=x.length();
    int m=y.length();

    cout<<"The length of Longest Common Subsequence is :";
   cout<<LCS_recursive(x,y,n,m);

}
