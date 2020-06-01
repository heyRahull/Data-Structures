/*
create a BST with the following elements : 50,30,20,40,70,60,80.


Binary Search Tree is :-
          50                               
        /    \                      
      30      70                    
     /  \     / \                             
    20   40  60 80                           
                                                 
 Inorder Traversal of the tree is : 50,30,20,40,70,60,80.                                             

*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

node *createNode(int val)//function to create a BST node 
{
    node *newnode;
    newnode=new node;
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    
    return newnode;
    
}


void preorder(node *root)//function to do preorder traversal of BST
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

node *insert(node *root,int key)//function to insert a new node in BST
{
    if(root==NULL)         //if the tree is empty create a new node
    return createNode(key);
   
    //otherwise recur down the tree
    if(key < root->data)           
    root->left=insert(root->left,key);
    if(key > root->data)
    root->right=insert(root->right,key);
    
    return root;
}

int main()
{
    node *root;
    root=NULL;
    root=insert(root,50);
    insert(root,30);
    insert(root,20);
    insert(root,40);
    insert(root,70);
    insert(root,60);
    insert(root,80);
    
    
    preorder(root);
}
