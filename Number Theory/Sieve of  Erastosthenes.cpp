/*For a given no. n, print all the primes smaller than or equal to n O(n log(log n))*/
#include <bits/stdc++.h>

using namespace std;

int main()

{
int n;
cin>>n;

int isprime[n+1];

for(int i=0;i<=n;i++)
isprime[i]=1;

isprime[0]=isprime[1]=0;

for(int i=2;i<=n;i++)
{
    if(isprime[i]==1)
    {
        for(int j=i*i;j<=n;j+=i)
        isprime[j]=0;
    }
}

for(int i=0;i<=n;i++)
{
    if(isprime[i]==1)
    cout<<i<<endl;
}

}
