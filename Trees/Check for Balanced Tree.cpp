int f=1;
    int solve(Node *root)
    {
        if(root==NULL)return 0;
        
        int ls= solve(root->left);
        int rs= solve(root->right);
        if(abs(ls-rs)>1)f=0;
        
        return max(ls,rs)+1;
    }
    
    bool isBalanced(Node *root)
    {
        //  Your Code here
        
        solve(root);
        return f;
        
    }
