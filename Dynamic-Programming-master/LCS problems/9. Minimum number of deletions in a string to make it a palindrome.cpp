/*
---------------------------Minimum number of deletions to make a string palindrome--------------------
Given a string of size ‘n’. The task is to remove or delete minimum number of characters from the string
so that the resultant string is palindrome.

Note: The order of characters should be maintained.

Examples :

Input : aebcbda
Output : 2
Remove characters 'e' and 'd'
Resultant string will be 'abcba'
which is a palindromic string

Input : geeksforgeeks
Output : 8
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
    string x="aebcbda";
    string y=x;
    reverse(y.begin(),y.end());
    int m=x.length();
    int n=y.length();

    cout<<"Minimum No. of deletions required to make the string a palindrome is : "<<m-LCS(x,y,m,n);//minimum no. of deletion =length of string - LCS
}
