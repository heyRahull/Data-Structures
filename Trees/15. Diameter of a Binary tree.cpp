 // Function to return the diameter of a Binary Tree.
    int ma;
    
    int solve(Node *root)
    {
        if(root==NULL)return 0;
        int x = solve(root->left);
        int y =solve(root->right);
        ma = max(ma,x+y+1);
        return max(x,y)+1;
    }
    
    int diameter(Node* root) {
        // Your code here
        ma =INT_MIN;
        solve(root);
        return ma;
    }
