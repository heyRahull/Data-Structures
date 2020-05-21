/*
--------------------------SCRAMBLE STRING(RECURSIVE)------------------------------------
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

Example 1:

Input: s1 = "great", s2 = "rgeat"
Output: true
Example 2:

Input: s1 = "abcde", s2 = "caebd"
Output: false
*/
#include<bits/stdc++.h>
using namespace std;

bool solve(string a,string b)
{
    if(a.compare(b)==0)//BASE CONDITION
        return true;   //if string a and string b both are same then return true


    if(a.length()<=1)//BASE CONDITION
        return false;//this is to satisfy constraint 2(i.e for a node there should not be any empty child)

    int n=a.length();
    bool flag=false;


    for(int i=1;i<=n-1;i++)
    {
        if((solve(a.substr(0,i),b.substr(0,i))==true&&solve(a.substr(i,n-1),b.substr(i,n-1))==true)||(solve(a.substr(0,i),b.substr(n-i,i))==true&&solve(a.substr(i,n-1),b.substr(0,n-i))==true))
        {
           flag=true;
           break;
        }
    }
    return flag;
}

int main()
{

    string a="great";
    string b="great";

    if(a.length()!=b.length())//BASE CONDITION
    {cout<<"false";           //if length of both the strings does not matches then string b cannot be a scramble string of string a so return false.
        return false;}

    if(a.length()==0&&b.length()==0)//BASE CONDITION
    {cout<<"true";               //if both the strings are empty then return true.
        return true;}            //(because even though the strings are empty,they are exactly similar),therefore return true.

    cout<<solve(a,b);
}
