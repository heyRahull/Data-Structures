int solve(string S,int start,int end)
    {
        if(start >= end)
        return 1;
        
        // if(start>end)
        // return 1;
        
        return ((S[start]==S[end]) && solve(S, start+1, end-1));
    }
	
	
	int isPalindrome(string S)
	{
	    // Your code goes here
	    int n = S.length();
	    int start =0;
	    int end = n-1;
	    
	    return solve(S,start,end);
	}
