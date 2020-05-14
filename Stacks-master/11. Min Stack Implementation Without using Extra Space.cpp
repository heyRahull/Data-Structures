/*  -------------------------------------MIN STACK IMPLEMENTATION WITHOUT USING EXTRA SPACE---------------------------------


Find minimum in a stack in O(1) time and O(1) extra space
Given a stack of integers. The task is to design a special stack such that maximum element can be found in O(1) time and O(1) extra space.

Examples:

Given Stack :

6
3
2 --> Minimum
5

So Output must be 2 when getmin() is called.


The different functions that we have used in this program are :
push1()
pop1()
top1()
getmin()

And the variable min_ele which will store the minimum element .

*/

#include<bits/stdc++.h>
#include<stack>
using namespace std;

stack <int> s;
int min_ele;     //declaring  a variable min_ele which will contain the minimum element.

void push1(int x)  //Function for pushing an element into stack
{
    if(s.size()==0) //if the stack is empty
    {
        s.push(x);//push the element into the stack
        min_ele=x;//and assign the element to min_ele variable(set the element as minimum element)
    }
    else
    {
        if(x>=min_ele)//if the element to be pushed is greater than the minimum element then push the element onto stack
            s.push(x);

        else if(x<min_ele)//if the element to be pushed is smaller than the minimum element
        {
            s.push(2*x - min_ele); //use this formula to push into stack(this very helps in keeping the track of previous min_ele value)
            min_ele=x;  //set the element as minimum element
        }
    }
}

void pop1()  //Function for popping an element from stack
{

    if(s.size()==0)
        cout<<"stack empty";
    else
    {

        if(s.top()>=min_ele) //if the top of the stack is greater than the minimum element then pop it
            s.pop();
        else if(s.top()<min_ele)//if the top of the stack is smaller than the minimum element then
        {
            min_ele =2*min_ele - s.top(); //use this formula to set new value to min_ele
            s.pop();  //pop the value of top of the stack
        }
    }
}

int top1()  //Function for finding the top of the element
{

    if(s.size()==0)
        cout<<"stack empty";
    else
    {

        if(s.top()>=min_ele)
            return s.top();
        else if(s.top()<min_ele)//if the top of the stack is smaller than the minimum element return minimum element as the top of the stack
            return min_ele;
    }
}

int getmin()  //Function which will return minimum element
{
    if(s.size()==0)
        cout<<"-1";
    else cout<<min_ele;

}

int main()
{
push1(5);
push1(2);
push1(3);
push1(6);
s.top();
pop1();
getmin();

}
