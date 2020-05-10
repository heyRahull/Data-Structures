/*
The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and
we need to calculate span of stock’s price for all n days.
The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just
before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.


For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85},
 then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}


*/

#include<iostream>    //STOCK SPAN PROBLEM is a variation of Nearest greater Left Problem.
#include<vector>
#include<stack>

using namespace std;

int main(){
	int arr[] = {100,80,60,70,60,75,85};
	int n = sizeof(arr)/sizeof(arr[0]);

	vector<int> v;

	stack <pair<int,int>> s;

	for(int i=0 ; i<n ; i++){
		if(s.size()==0)
			v.push_back(-1);

		else if(s.top().first > arr[i] && s.size()>0)
			v.push_back(s.top().second);              //in the vector we store the address.

		else if(s.top().first <= arr[i] && s.size()>0){
			while(s.size()>0 && s.top().first <=arr[i])
				s.pop();

			if(s.size()==0)
				v.push_back(-1);
			else
				v.push_back(s.top().second);
		}
		s.push({arr[i],i});         // In the stack we push both the value of the element and the index of the element
	}



	for(int i=0 ; i<v.size() ; i++)
		v[i] = i-v[i];


	for(int i=0 ; i<v.size() ; i++)
		cout<<arr[i]<<"-->"<<v[i]<<"\n ";

	return 0;
}

