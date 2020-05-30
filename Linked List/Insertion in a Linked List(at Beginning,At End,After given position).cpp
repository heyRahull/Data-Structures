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
int count1=0;

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
    count1=0;
    temp=head;
    cout<<"\nThe elements in the linked list are : ";
    while(temp!=NULL)
    {
    cout<<temp->data<<" ";
    temp=temp->next;
    count1++;
    }
    cout<<"\nThe no. of nodes in the linked list are : "<<count1;
}

void insertAtBeginning()//Function for inserting nodes at the beginning of linked list
{
    newnode = new node;
    cout<<"\n\nEnter data you want to insert at the beginning of linkedlist: ";
    cin>>newnode->data;
    newnode->next=head;
    head=newnode;

}


void insertAtEnd()//Function for inserting nodes at the end of linked list
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

void insertAfterNode()//Function for inserting nodes after a given position
{
    int pos;
    int i=1;
    cout<<"\nEnter the position after which you want to enter the element : ";
    cin>>pos;
    
    if(pos>count1){
    cout<<"-------------------------Invalid Position---------------------------";
    return;
        
    }
    else
    {
        temp=head;
        while(i<pos)
        {
            temp=temp->next;
            i++;
            
        }
    }
    
    newnode =new node;
    
    cout<<"\nEnter the data for the node : ";
    cin>>newnode->data;
    
    newnode->next=temp->next;
    temp->next=newnode;
    
    
}


int main()
{
    
    createNode();
    printNode();
    
    int cont;
    
    while(1)
    {
        cout<<"\n\nEnter 1. for Insert Element at beginning ";
        cout<<"\nEnter 2. for Insert Element at the End ";
        cout<<"\nEnter 3. for Insert Element after a given position";
        cin>>cont;
        
        if(cont==1)
        {
          insertAtBeginning();
            printNode();
        }
        else if(cont==2)
        {
            insertAtEnd();
            printNode();
        }
        else if(cont==3)
        {
            
            insertAfterNode();
            printNode();
        }
        else
            break;

    }
}
