/*
AREA OF Max Rectangle in Binary Matrix

Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all ones and return its area.

Example :

A : [  0 1 1 0
       1 1 1 1
       1 1 1 1
       1 1 0 0
    ]

Output : 8    //[1 1 1 1
                 1 1 1 1]

As the max area rectangle is created by the 2x2 rectangle created by (0,1), (0,2), (1,1) and (1,2)

*/


//There are just minor changes in main() ,the MAH function is same as the previous code of Maximum Area Histogram.

#include <bits/stdc++.h>
#include<stack>
#include<vector>
using namespace std;




MAH(vector<int>arr,int n)      //Function for finding Maximum Area Of Histogram
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



int area[n]; //declaration of the array named area which will store the maximum area of each building/histogram.

////cout<<"area :- \n";

//cout<<"Height of Buildings is: ";
for(int j=0;j<n;j++)
{
  //  cout<<arr[j]<<"\t";
    area[j]=width[j] *arr[j];
    ////cout<<arr[j]<<"-->"<<area[j]<<"\n";
}

//cout<<"\n\nMaximum Area of Histogram is:"<<*max_element(area,area+n)<<"\n";   //This max function will return the maximum area of histogram.

return *max_element(area,area+n);





}


//The Changes are in the main() function only,the MAH function is same as previous code(i.e Maximum area of Histogram)

int main()
{
vector<int> arr;                            //arr is the name of the vector
    //int arr[] = {6,2,5,4,5,1,6};

    int matrix[][4]={                       //declaring a 2-d array(i.e binary matrix)
                        {0,1,1,0},
                        {1,1,1,1},
                        {1,1,1,1},
                        {1,1,0,0},
                    };
int n= 4;
    //MAH(arr,n);


cout<<"The Binary Matrix is :"<<"\n";       //printing the binary matrix
for(int i=0;i<4;i++)
{
     for(int j=0;j<4;j++){
    cout<<matrix[i][j]<<"\t";
    }cout<<"\n";
}


for(int i=0;i<4;i++)
    arr.push_back(matrix[0][i]);
int mx =MAH(arr,n);                 //mx is the variable that contains the maximum area.



for(int i=1;i<4;i++)
 {
     for(int j=0;j<4;j++)
    {
        if(matrix[i][j]==0)
            arr[j]=0;
        else
            arr[j]=arr[j]+matrix[i][j];
    }
    mx=max(mx,MAH(arr,n));
}
cout<<"\nArea of Maximum Size Rectangle in Binary Matrix is:"<<mx<<"\n";




}
