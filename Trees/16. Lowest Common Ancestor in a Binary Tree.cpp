//Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       if(root==NULL)return NULL;
       
       if(root->data==n1 || root->data==n2)
       return root;
       
       Node *l=lca(root->left,n1,n2);
       Node *r=lca(root->right,n1,n2);
       
       if(l!=NULL && r!=NULL)return root;
       if(l!=NULL)return l;
       else
       return r;
    }
