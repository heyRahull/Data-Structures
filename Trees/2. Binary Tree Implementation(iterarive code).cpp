#include<bits/stdc++.h>
#include <iostream>

using namespace std;
struct node{
int data;
node *left;
node *right;
};

node *newnode;
node *createNode(int val)
{
    newnode= new node;
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    
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
    int val;
    node *root;
    root=createNode(1);
    root->left=createNode(2);
    root->right=createNode(3);
    root->left->left=createNode(4);

cout<<"The preorder traversal of binary tree is ";
    preorder(root);
}
