int isSumProperty(Node *root)
    {
     // Add your code here
     int f;
     int sum=0;
     if(root==NULL)return 1;
     if(root->left==NULL && root->right==NULL)return 1;
     
     if(root->left!=NULL) sum+=root->left->data;
     if(root->right!=NULL) sum+=root->right->data;
     
     return ((sum==root->data)&&(isSumProperty(root->left))&&(isSumProperty(root->right)));
    }
