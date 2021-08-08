/*
You are given two arrays a[] (integer) and b[] (char). The ith value of a[] corresponds to the ith value of b[]. Sort the array b[] with respect to a[].

Example 1:

Input:
a[] = {3, 1, 2}
b[] = {'G', 'E', 'K'}
Output:
E K G
Explanation: Here 3 corresponds to G,
1 corresponds to 'E', 2 corresponds to 'K'
 

Example 2:

Input:
a[] = {4, 1, 3, 2}
b[] = {'A', 'X', 'B', 'Y'}
Output:
X Y B A
Explanation:
*/

void sortArray(int a[], char b[], int n){
    
    // code here
    pair<int,char>pa[n];
    for(int i=0;i<n;i++)
    pa[i]={a[i],b[i]};
    
    sort(pa,pa+n);
    
    for(int i=0;i<n;i++)
    cout<<pa[i].second<<" ";
    
}
