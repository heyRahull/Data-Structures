/*
This is a single program where i have performed three operations of deletion in linked lists :
1.Deleting an element from the Beginning of a linked list.
2.Deleting an element from the End of a linked list.
3.Deleting an element from the given position of a linked list.
*/
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

struct node{
 int data;
 node *next;
};

node *newnode,*temp,*head,*prevNode;;
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

void deleteFromBeginning()//deleting a node from the beginning of a linked list
{
    temp=head;
    head=head->next;
    free(temp);

}

void deleteFromEnd()//deleting a node from the end of a linked list
{
    
    temp=head;
    
    while(temp->next!=NULL)
    {
        prevNode=temp;
        temp=temp->next;
        
    }
    
    if(temp==head)
    {
        head=NULL;
    }
    else
        prevNode->next=NULL;
    free(temp);
}

void deleteFromPos()//delete from a given position
{
    temp=head;
    int pos;
    int i=1;
    
    cout<<"\nEnter the position from where you want to delete the node : ";
    cin>>pos;
    
    if(pos>count1)
    {
        cout<<"-------------------------Invalid Poisition----------------------";
        return;
    }
    else
    {
        while(i<pos)
        {
            prevNode=temp;
            temp=temp->next;
            i++;
        }
        prevNode->next=temp->next;
        free(temp);
    }
}

int main()
{
    createNode();
    printNode();
    
    int choice;
    
    while(1)
    {
        cout<<"\n\nEnter 1. for Delete Element from beginning ";
        cout<<"\nEnter 2. for Delete Element from the End ";
        cout<<"\nEnter 3. for Delete Element from a given position";
        cin>>choice;
        
        if(choice==1)
        {
          deleteFromBeginning();
            printNode();
        }
        else if(choice==2)
        {
            deleteFromEnd();
            printNode();
        }
        else if(choice==3)
        {
            
          deleteFromPos();
            printNode();
        }
        else
            break;

    }

}    
    
    
