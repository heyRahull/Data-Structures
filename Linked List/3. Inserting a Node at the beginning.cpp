/*
--------------------Inserting elements at the beginning of Linked List ------------------------

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
    int a[]={10,20,30,40,50};
    newnode = new node;
head=temp=newnode;


newnode->data=10; //inserting data in the first node
newnode->next=NULL;

for(int i=1;i<5;i++)
{
    newnode = new node;

    newnode->data=a[i];
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

cout<<"\nThe elements of linked list are : ";
while(temp!=NULL)
{
    cout<<temp->data<<" ";
    temp=temp->next;
    count++;
}
cout<<"\nThe no. of nodes in the linked list is : "<<count;

}

insertAtBeginning()
{
    newnode = new node;
    cout<<"\n\nEnter data you want to insert at the beginning of linkedlist: ";
    cin>>newnode->data;
    newnode->next=head;
    head=newnode;

}

int main()
{

createNode();
printNode();
insertAtBeginning();
printNode();

cout<<endl;
}
