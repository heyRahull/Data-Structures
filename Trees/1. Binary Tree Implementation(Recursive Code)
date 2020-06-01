#include<bits/stdc++.h>
#include <iostream>

using namespace std;
struct node{
int data;
node *left;
node *right;
};




node *createNode()
{
    node *newnode;
    newnode= new node;
    int elem;
    cout<<"\nEnter the data for the node,press -1 if you dont want the node to be created : ";
    cin>>elem;
    if(elem==-1)
    return 0;
    
    newnode->data=elem;
    cout<<"\nEnter left child of "<<elem;
    newnode->left=createNode();
    cout<<"\nEnter right child of "<<elem;
    newnode->right=createNode();
    
    return newnode;
}

void preorder(node *root)
{
    if(root==0)
    return;
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    node *root;
    root=0;
    root=createNode();
    
cout<<"The preorder traversal of binary tree is : ";
    preorder(root);
}
