/*

Palindrome Partitioning | DP-17
Given a string, a partitioning of the string is a palindrome partitioning if every substring of the partition is a palindrome.
For example,
“aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”.
Determine the fewest cuts needed for palindrome partitioning of a given string.


For example, minimum 3 cuts are needed for “ababbbabbababa”.
The three cuts are “a|babbbab|b|ababa”. If a string is palindrome, then minimum 0 cuts are needed.
 If a string of length n containing all different characters, then minimum n-1 cuts are needed.


*/

#include<bits/stdc++.h>
using namespace std;

bool ispalindrome(string s,int i,int j)
{
    if(i==j)
        return true;
    if(i>j)
        return true;
    while(i<j)
    {
        if(s[i]!=s[j])
        return false;

     i++;
     j--;
    }
return true;
}


int solve(string s,int i,int j)
{
    if(i>=j)
        return 0;

    if(ispalindrome(s,i,j)==true)
        return 0;

    int mn=INT_MAX;

    for(int k=i;k<=j-1;k++)
    {
        int temp=1+solve(s,i,k)+solve(s,k+1,j);

        if(temp<mn)
            mn=temp;
    }
    return mn;
}



int main()
{
    string s="nitik";
    int i=0;
    int j=s.length()-1;
    cout<<" The Number of partitions required are : ";
    cout<<solve(s,i,j);
}
