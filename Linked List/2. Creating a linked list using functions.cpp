/*
--------------------Implementing a Linked List using functions------------------------

*/
#include<bits/stdc++.h>
using namespace std;

struct node{ //declaring a structure of type node which contain a variable data(of type int) and a next pointer
int data;
node *next;
};

node *head=0,*newnode,*temp; //declaring all the variables globally so that they can be accessed by all the functions.
int n,element;

createNode() //Function for creating the nodes of linked list
{
    newnode = new node;
head=temp=newnode;


cout<<"Enter the data for node 1 : ";
cin>>element;

newnode->data=element;
newnode->next=NULL;

for(int i=2;i<=n;i++)
{
    newnode = new node;

    cout<<"Enter the data for node "<<i<<" : ";
    cin>>element;

    newnode->data=element;
    newnode->next=NULL;

    temp->next=newnode;
    temp=newnode;
}


}

printNode() //function for printing the linked list
{
//code for printing the linked list

temp=head;
int count=0;

cout<<"The elements of linked list are : ";
while(temp!=NULL)
{
    cout<<temp->data<<" ";
    temp=temp->next;
    count++;
}
cout<<"\n\n\nThe no. of nodes in the linked list is : "<<count;

}

int main()
{
cout<<"Enter the number of nodes you want to create : ";
cin>>n;

if(n==0)
{
    cout<<"Linked list is not created";
    return 0;
}


createNode();

printNode();
}
