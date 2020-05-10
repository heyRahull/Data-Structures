/*
---------------------------Minimum number of Insertions to make a string palindrome--------------------




Given a string str, the task is to find the minimum number of characters to be inserted to convert it to palindrome.
Before we go further, let us understand with few examples:

ab: Number of insertions required is 1 i.e. bab
aa: Number of insertions required is 0 i.e. aa
abcd: Number of insertions required is 3 i.e. dcbabcd
abcda: Number of insertions required is 2 i.e. adcbcda which is same as number of insertions in the substring bcd(Why?).
abcde: Number of insertions required is 4 i.e. edcbabcde


INPUT : string x="aebcbda";
OUTPUT : 2

Explanation :
We will find the number of deletions that will be required to make it a palindrome,
bcoz the number of characters that are required to be deleted ,that much amount of characters we need to insert
in the string so that the extra characters will form a pair and we will obtain a palindrome.
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

    cout<<"Minimum No. of Insertions required to make the string a palindrome is : "<<m-LCS(x,y,m,n);//minimum no. of deletion =length of string - LCS
}
