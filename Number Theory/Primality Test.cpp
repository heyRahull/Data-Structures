/*Find whether a given number is prime or not*/
#include <iostream>
using namespace std;

bool isPrime(int N)
{
        if(N==1)
	    return false;
	   
	    
	        for(int i=2;i*i<=N;i++)
	        {
	            if(N%i==0)
	             return false;
	        }
	        return true;
	    
}

int main() {
	int T;
	cin>>T;
	
	while(T--)
	{
	    int N;
	    cin>>N;
	    
	    if(isPrime(N) == 0)
	    cout<<"no"<<endl;
	    else
	    cout<<"yes"<<endl;
	}
	
}
