/* --------------------------MIN STACK IMPLEMENTATION-----------------------------

Consider the following SpecialStack
16  --> TOP
15
29
19
18

When getMin() is called it should return 15,
which is the minimum element in the current stack.



If we do pop two times on stack, the stack becomes
29  --> TOP
19
18

When getMin() is called, it should return 18
which is the minimum in the current stack.
*/

#include<bits/stdc++.h>
#include<stack>
using namespace std;

stack<int>s;
stack<int>ss;

void push1(int a)
{
    s.push(a);
    if(ss.size()==0||ss.top()>=a)
        ss.push(a);

    return;

}

int pop1()
{
    if(s.size()==0)
        return -1;
    int ans=s.top();
    s.pop();
    if(ss.top()==ans)
        ss.pop();
    return ans;

}


int getmin()
{

    if(ss.size()==0)
        cout<<"Stack empty";
    else
    cout<<ss.top()<<endl;

}


int main()
{

    push1(18);
    push1(19);
    push1(29);
    push1(15);
getmin();//at this point the min element is 15
    pop1();
    getmin();//at this point the min element is 18
    push1(16);
  getmin();//at this point the min element is 16
    pop1();
    getmin();//at this point the min element is 18
    pop1();
  getmin();//at this point the min element is 18
    pop1();
  getmin();//at this point the min element is 18
    pop1();
  getmin();//at this point the min element is (stack empty)

}
