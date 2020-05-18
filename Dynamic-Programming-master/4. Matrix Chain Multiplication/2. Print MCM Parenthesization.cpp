/*

--------------------------Matrix Chain Multiplication | DP-8------------------------
Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications.

We have many options to multiply a chain of matrices because matrix multiplication is associative. In other words, no matter how we parenthesize the product, the result will be the same. For example, if we had four matrices A, B, C, and D, we would have:

    (ABC)D = (AB)(CD) = A(BCD) = ....
However, the order in which we parenthesize the product affects the number of simple arithmetic operations needed to compute the product, or the efficiency.



 Input: p[] = {40, 20, 30, 10, 30}
  Output: 26000
  There are 4 matrices of dimensions 40x20, 20x30, 30x10 and 10x30.
  Let the input 4 matrices be A1, A2, A3 and A4.  The minimum number of
  multiplications are obtained by putting parenthesis in following way
  (A1(A2A3))A4 --> 20*30*10 + 40*20*10 + 40*10*30

  Input: p[] = {10, 20, 30, 40, 30}
  Output: 30000
  There are 4 matrices of dimensions 10x20, 20x30, 30x40 and 40x30.
  Let the input 4 matrices be A, B, C and D.  The minimum number of
  multiplications are obtained by putting parenthesis in following way
  ((AB)C)D --> 10*20*30 + 10*30*40 + 10*40*30

  Input: p[] = {10, 20, 30}
  Output: 6000
  There are only two matrices of dimensions 10x20 and 20x30. So there
  is only one way to multiply the matrices, cost of which is 10*20*30
*/#include<bits/stdc++.h>
using namespace std;
int t[6][6];
int bracket[6][6];

int solve(int arr[],int i,int j)
{
int mn=INT_MAX;
    if(i>=j)
        return 0;

    if(t[i][j]!=-1)
        return t[i][j];

    for(int k=i;k<=j-1;k++)
    {
        int tempans =solve(arr,i,k)+solve(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);

        if(tempans<mn){
            mn=tempans;
            t[i][j]=mn;
            bracket[i][j]=k;
        }
    }

return t[i][j];
}

void Parenthesization(int i,int j){
if(i==j)
cout<<"A"<<i;
else
{
    cout<<"(";
    Parenthesization(i,bracket[i][j]);
    Parenthesization(bracket[i][j]+1,j);
    cout<<")";
}

}

int main()
{
int arr[]={40,20,30,10,30};
int i=1;
int j=sizeof(arr)/sizeof(arr[0])-1;

memset(t,-1,sizeof(t));

cout<<"Minimum Number of multiplications are : ";
cout<<solve(arr,i,j)<<endl;

cout<<"The optimal parenthesization is :";
Parenthesization(i,j);

}
