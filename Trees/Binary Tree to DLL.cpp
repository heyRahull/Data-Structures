void solve(Node *root, Node *&head,Node *&prev,int &f)
    {
        if(root==NULL)return;
        solve(root->left,head,prev,f);
        if(f==0)
        {
            head = root;
            prev = root;
            f =1;
        }
        else
        {
            prev->right =root;
            prev->right->left=prev;
            prev =prev->right;
        }
        solve(root->right,head,prev,f);
    }
    
    
    Node * bToDLL(Node *root)
    {
        // your code here
        Node *head = NULL;
        Node *prev =  NULL;
        int f=0;
        solve(root,head,prev,f);
        return head;
    }
