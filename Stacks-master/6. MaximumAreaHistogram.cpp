/*
MAXIMUM AREA OF A HISTOFRAM   AKA   LARGEST RECTANGULAR AREA IN A HISTOGRAM

Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars.
For simplicity, assume that all bars have same width and the width is 1 unit.
For example, consider the following histogram with 7 bars of heights {6, 2, 5, 4, 5, 2, 6}.
The largest possible rectangle possible is 12 

histogram
*/

#include <bits/stdc++.h>
#include<stack>
#include<vector>
using namespace std;




MAH(int arr[],int n)      //Function for finding Maximum Area Of Histogram
{
    vector<int>nsl;       //Vector created for storing the index of Nearest Smallest Left Element
    vector<int>nsr;        //Vector created for storing the index of Nearest Smallest Right Element

    stack<pair<int,int>>left1;  //Creating a paired Stack which will be required during nsl operation
    stack<pair<int,int>>right1; //Creating a paired Stack which will be required during nsr operation



    //for loop which will perform nsl operation.
    for(int i=0;i<=n;i++)
    {
        if(left1.size() == 0)    //if the stack is empty
        {
          nsl.push_back(-1);

        }
        else if(left1.size()>0 && left1.top().first<arr[i])    //if the value in the top of the stack is lesser than the current value of array
        {
            nsl.push_back(left1.top().second);
        }
        else if(left1.size()>0 && left1.top().first>=arr[i])  //if the value in the top of the stack is larger than the current value of array
        {
            while(left1.size()>0 && left1.top().first>=arr[i])
            {
                left1.pop();                    //keep on popping the elements of stack until either the stack gets empty or the top of the stack
                                                //becomes lesser than the current value of array.

            }
            if(left1.size()==0)
            {
                nsl.push_back(-1);
            }
            else
                {
                nsl.push_back(left1.top().second);
                }
        }

    left1.push({arr[i],i});   //Pushing the current array element with its index onto the stack.
    }

/*

      //Printing the Index of Nsl elements:-

        cout<<"Index of NSl element :- \n";
        for(int i=0;i<=n-1;i++)
        {
            cout<<arr[i]<<"-->"<<nsl[i]<<"\n";

        }
        cout<<"\n";
*/


//for loop which will perform nsr operation.
for(int i=n-1;i>=0;i--)
    {
        if(right1.size() == 0)    //if the stack is empty
        {
          nsr.push_back(n);

        }
        else if(right1.size()>0 && right1.top().first<arr[i])    //if the value in the top of the stack is lesser than the current value of array
        {
            nsr.push_back(right1.top().second);
        }
        else if(right1.size()>0 && right1.top().first>=arr[i])  //if the value in the top of the stack is larger than the current value of array
        {
            while(right1.size()>0 && right1.top().first>=arr[i])  //keep on popping the elements of stack until either the stack gets empty or the top of the stack
                                                //becomes lesser than the current value of array.
            {
                right1.pop();

            }
            if(right1.size()==0)
            {
                nsr.push_back(n);
            }
            else
                {
                nsr.push_back(right1.top().second);
                }
        }

    right1.push({arr[i],i});
    }

        reverse(nsr.begin(),nsr.end());


/*

        //Printing the Index of Nsr elements:-

        cout<<"Index of NSR element :- \n";
        for(int i=0;i<=n-1;i++)
        {
            cout<<arr[i]<<"-->"<<nsr[i]<<"\n";

        }
        cout<<"\n";

*/

int width[n];  //declaration of the array named width which will store the maximum width of each building/histogram.

////cout<<"width :- \n";
for(int j=0;j<n;j++)
{
    width[j]=nsr[j] -nsl[j]-1;
    ////cout<<arr[j]<<"-->"<<width[j]<<"\n";
}
cout<<"\n";


int area[n]; //declaration of the array named area which will store the maximum area of each building/histogram.

////cout<<"area :- \n";

cout<<"Height of Buildings is: ";
for(int j=0;j<n;j++)
{
    cout<<arr[j]<<"\t";
    area[j]=width[j] *arr[j];
    ////cout<<arr[j]<<"-->"<<area[j]<<"\n";
}

cout<<"\n\nMaximum Area of Histogram is:"<<*max_element(area,area+n)<<"\n";   //This max function will return the maximum area of histogram.


}
int main()
{

    int arr[] = {6,2,5,4,5,1,6};
    int n= sizeof(arr)/sizeof(arr[0]);
    MAH(arr,n);
    return 0;
}
