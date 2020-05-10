/*
Find minimum number of coins that make a given value
Given a value V, if we want to make change for V cents,
and we have infinite supply of each of C = { C1, C2, .. , Cm} valued coins,
what is the minimum number of coins to make the change?


Examples:

Input: coins[] = {1 ,2, 3}, sum = 5
Output: Minimum 2 coins required
We can use one coin of 2 cents and one of 3 cents

Input: coins[] = {9, 6, 5, 1}, sum = 11
Output: Minimum 2 coins required
We can use one coin of 6 cents and 1 coin of 5 cents
*/
#include<bits/stdc++.h>
using namespace std;

int minCoins(int coins[], int sum, int n)
{
	int t[n+1][sum+1];

	// Initialize first row as Infinite and first column as 0.
	for (int i=0; i<n+1; i++)
    {
        for (int j=0; j<n+1; j++)
        {
            if(i==0)
            {
              t[i][j] = INT_MAX-1;
            }
        else
            if(j==0)
            {
              t[i][j] = 0;
            }
        }
    }

    //Initializing the values in the second row.(This is the only problem where we are asked to initialize the second row.)
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(j%coins[i]==0)
            {
                t[i][j]=j/coins[0];
            }
            else
                t[i][j]=INT_MAX-1;

        }
    }


    //writing the dp code for the remaining table(this is the same code that we wrote in unbounded knapsack)
    for(int i=2;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(coins[i-1]<=j)
            {
                t[i][j]=min(1+t[i][j-coins[i-1]],t[i-1][j]);
            }
            else
                t[i][j]=t[i-1][j];
        }

    }
    return t[n][sum];
}

// Driver program to test above function
int main()
{
	int coins[] = {1, 2, 3};
	int n = sizeof(coins)/sizeof(coins[0]);
	int sum = 5;
	cout << "Minimum coins required is "
		<< minCoins(coins, sum, n);
	return 0;
}
