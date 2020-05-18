/*

Boolean Parenthesization Problem | DP-37
Given a boolean expression with following symbols.

Symbols
    'T' ---> true
    'F' ---> false
And following operators filled between symbols

Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true

Let the input be in form of two arrays one contains the symbols (T and F) in order and other contains operators (&, | and ^}

Examples:

Input: symbol[]    = {T, F, T}
       operator[]  = {^, &}
Output: 2
The given expression is "T ^ F & T", it evaluates true
in two ways "((T ^ F) & T)" and "(T ^ (F & T))"

Input: symbol[]    = {T, F, F}
       operator[]  = {^, |}
Output: 2
The given expression is "T ^ F | F", it evaluates true
in two ways "( (T ^ F) | F )" and "( T ^ (F | F) )".

Input: symbol[]    = {T, T, F, T}
       operator[]  = {|, &, ^}
Output: 4
The given expression is "T | T & F ^ T", it evaluates true
in 4 ways ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T)
and (T|((T&F)^T)).
*/
#include<bits/stdc++.h>
using namespace std;

int solve(string s,int i,int j,bool istrue)
{
    int ans=0;
    if(i>j)
        return false;
    if(i==j)
    {
        if(istrue==true)
        {
            if(s[i] == 'T')
                return 1;
            else
                return 0;
        }
        else
            {
            if(s[i] == 'F')
                return 1;
            else
                return 0;
            }
    }



    for(int k=i+1;k<=j-1;k=k+2)
    {
        int lt=solve(s,i,k-1,true);
        int lf=solve(s,i,k-1,false);
        int rt=solve(s,k+1,j,true);
        int rf=solve(s,k+1,j,false);

        if(s[k] == '&')
        {
            if(istrue == true)
                ans=ans+(lt*rt);
            else
                ans=ans+(lt*rf)+(lf*rt)+(lf*rf);
        }
        else if(s[k] == '|')
        {
            if(istrue==true)
                ans=ans+(lt*rt)+(lt*rf)+(lf*rt);
            else
                ans=ans+(lf*rf);
        }
        else if(s[k] == '^')
        {
            if(istrue==true)
                ans=ans+(lf*rt)+(lt*rf);
            else
                ans=ans+(lf*rf)+(lt*rt);
        }

    }
    return ans;

}

int main()
{
    string s="T^F&T";
    int i=0;
    int j=s.length()-1;
    bool istrue=true;


    cout<<"The no. of ways we can parenthesize the expression so that the value of expression evaluates to true : ";
    cout<<solve(s,i,j,true);

}
