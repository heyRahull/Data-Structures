/*

-----------------------Shortest Common Supersequence-----------------------
Given two strings str1 and str2, find the shortest string that has both str1 and str2 as subsequences.
Examples :

Input:   str1 = "geek",  str2 = "eke"
Output: 5(which is length of "geeke")

Input:   str1 = "AGGTAB",  str2 = "GXTXAYB"
Output:  9(which is the length of "AGXGTXAYB")
*/
#include<bits/stdc++.h>
using namespace std;

LCS(string x,string y,int m,int n)//this function calculates length of LCS
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
 string x="geek";
 string y="eke";
 int m=x.length();
 int n=y.length();

 cout<<"The shortest common supersequence is :";
 cout<<m+n-LCS(x,y,m,n);//sum length of both the substring minus the the length of LCS,
                        //this will give us the length of the shortest common supersequence.

}
