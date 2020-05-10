/*
-----------------------------Sequence Pattern Matching---------------------

Given two strings 'x' and 'y' .Check if the string 'x' is present in string 'y'
If it is present then return true ,otherwise return false.


Input:

string x="axy"
string y="adxcpy"

output:
true

Explanation:
The string "axy" is present in the string "adxcpy".
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


    return t[m][n];
}

int main()
{
    string x="axy";
    string y="adxcpy";
    int m=x.length();
    int n=y.length();


    cout<<"The String '"<<x<<"' is present in the string '"<<y<<"' : " ;
    if(m==LCS_tabulation(x,y,m,n))
    {
        cout<<"true";
    }
    else
        cout<<"false";

}
