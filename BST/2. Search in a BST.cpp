#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node* left;
    Node* right;
    Node(int x)
    {
        key =x;
        left = NULL;
        right == NULL;
    }
};

bool search(Node* root,int x)
{
    if(root==NULL)return false;
    else if(root->key == x)return true;
    else if(root->key > x) search(root->left,x);
    else if(root->key < x) search(root->right,x);
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(19);
    cout<<"ans -> "<<search(root,19);
}
