#include<bits/stdc++.h>
#include <iostream>
using namespace std;

struct node{
 int data;
 node *next;
};

node *newnode,*temp,*head,*prevNode;
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

void reverse()//function for reversing the linkedlist
{
    node *prevNode,*currentNode,*nextNode;
    prevNode=0;
    currentNode=nextNode=head;
    
    while(nextNode!=NULL)
    {
        nextNode=nextNode->next;
        currentNode->next=prevNode;
        prevNode=currentNode;
        currentNode=nextNode;
    }
    
    head=prevNode;


}

int main()
{
    cout<<"\nInitially the linked list is : ";
    createNode();
    printNode();
    cout<<"\n\nAfter revering the Linked list : ";
    reverse();
    printNode();
  
}    
    
    
