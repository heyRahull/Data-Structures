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
