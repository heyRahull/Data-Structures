 // Function to get the maximum width of a binary tree.
    int getMaxWidth(Node* root) {

        // Your code here
        if(root==NULL)return 0;
        queue<Node *>q;
        q.push(root);
        int ma = INT_MIN;
        
        while(q.empty()==false)
        {
            int count = q.size();
            ma = max(ma,count);
            while(count--)
            {
                Node *curr = q.front();
                q.pop();
                
                if(curr->left!=NULL)q.push(curr->left);
                if(curr->right!=NULL)q.push(curr->right);
            }
        }
        return ma;
    }
