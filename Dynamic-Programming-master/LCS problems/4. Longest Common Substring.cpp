/*
Longest Common Substring | DP-29
Given two strings ‘X’ and ‘Y’, find the length of the longest common substring.
Examples :

Input : X = “GeeksforGeeks”, y = “GeeksQuiz”
Output : 5
The longest common substring is “Geeks” and is of length 5.

Input : X = “abcdxyz”, y = “xyzabcd”
Output : 4
The longest common substring is “abcd” and is of length 4.

Input : X = “zxabcdezy”, y = “yzabcdezx”
Output : 6
The longest common substring is “abcdez” and is of length 6.


Input: x="abcde",y="abfce"
output:2
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
            t[i][j]=0;
        }
    }


    int ans=0;


    for(int i=0;i<m+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
           ans=max(t[i][j],ans);
        }

    }
return ans;

}

int main()
{
    string x="abcde";
    string y="abfce";
    int m=x.length();
    int n=y.length();

    cout<<"The length of Longest Common Subsequence is : ";
    cout<<LCS_tabulation(x,y,m,n);
}
