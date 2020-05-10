/*   NEAREST GREATEST RIGHT :-


Given an array, print the Next Greater Element (NGE) for every element.
The Next greater Element for an element x is the first greater element on the right side of x in array. 
Elements for which no greater element exist, consider next greater element as -1.

Examples:

1.For any array, rightmost element always has next greater element as -1.
2.For an array which is sorted in decreasing order, all elements have next greater element as -1.
3.For the input array [4, 5, 2, 25}, the next greater elements for each element are as follows.

                       
 Element       NGE
   4      -->   5
   5      -->   25
   2      -->   25
   25     -->   -1

*/


#include <bits/stdc++.h>
using namespace std;

int main()
{
	int arr[] = {1,3,2,4};
	int n = sizeof(arr)/sizeof(arr[0]);
	vector<int> v;
	stack<int> s;

	for(int i=n-1 ; i>=0 ; i--)
        {
		if(s.size()==0)
			v.push_back(-1);

		else if(s.top()>arr[i] && s.size()>0)
			v.push_back(s.top());

		else if(s.top()<=arr[i] && s.size()>0){
			while(s.size()>0 && s.top()<=arr[i])
				s.pop();

			if(s.size()==0)
				v.push_back(-1);
			else
				v.push_back(s.top());
		}
		s.push(arr[i]);

	}
    reverse(v.begin(), v.end());

	for(int i=0 ; i<v.size() ; i++)
		cout<<arr[i]<<"-->"<<v[i]<<"\n ";

	return 0;
}

