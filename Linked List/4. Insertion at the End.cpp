#include<bits/stdc++.h>
#include <iostream>
using namespace std;

struct node{
 int data;
 node *next;
};

node *newnode,*temp,*head;
int element;
int n;

void createNode()//Function for creating nodes 
{
    
    int a[]={10,20,30,40};
    
    newnode=new node;
    temp=head=newnode;
    
    
    newnode->data=a[0];
    newnode->next=NULL;
    
    for(int i=1;i<4;i++)
    {
        newnode=new node;
        
       
        newnode->data=a[i];
        newnode->next=NULL;
    
        temp->next=newnode;
        temp=newnode;
        
        
    }
}


void printNode()//Function for printing nodes
{
    temp=head;
    cout<<"The elements in the linked list are : ";
    while(temp!=NULL)
    {
    cout<<temp->data<<" ";
    temp=temp->next;
    }
}

void insertAtEnd()//Functionn for inserting nodes at the end of linked list
{
    newnode =new node;
    
    cout<<"\nEnter the data for the node : ";
    cin>>newnode->data;
    
    newnode->next=NULL;
    
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}

int main()
{
    
    createNode();
    printNode();
    insertAtEnd();
    printNode();
    
    
    
    int cont;
    
    while(1)
    {
        cout<<"\nEnter 1 if you enter more data,otherwise enter 0 : ";
        cin>>cont;
        if(cont==1)
        {
            insertAtEnd();
            printNode();
        }
        else
            break;

    }
    }
