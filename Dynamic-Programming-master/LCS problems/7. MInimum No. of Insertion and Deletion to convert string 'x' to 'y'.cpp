/*

---------------Minimum number of deletions and insertions to transform one string into another---------------
Given two strings ‘str1’ and ‘str2’ of size m and n respectively. The task is to remove/delete and insert minimum number of characters from/in str1 so as to transform it into str2. It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.

Examples:

Input : str1 = "heap", str2 = "pea"
Output : Minimum Deletion = 2 and
         Minimum Insertion = 1

p and h deleted from heap
Then, p is inserted at the beginning
One thing to note, though p was required yet
it was removed/deleted first from its position and
then it is inserted to some other position.
Thus, p contributes one to the deletion_count
and one to the insertion_count.

Input : str1 = "geeksforgeeks", str2 = "geeks"
Output : Minimum Deletion = 8
         Minimum Insertion = 0
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
 string x="heap";
 string y="pea";
 int m=x.length();
 int n=y.length();

 cout<<"Number of Deletions : "<<m-LCS(x,y,m,n)<<"\n";//number of deletions required to obtain the desired string
 cout<<"Number of Insertions : "<<n-LCS(x,y,m,n);//number of insertions required to obtain the desired string


}
