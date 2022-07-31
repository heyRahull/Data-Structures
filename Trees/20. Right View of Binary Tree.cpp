 vector<int> rightView(Node *root)
    {
       // Your Code here
       
       vector<int>v;
       if(root==NULL)return v;
       queue<Node *>q;
       q.push(root);
       
       while(q.empty() == false)
       {
           int count = q.size();
            Node *curr;
           while(count--)
           {
               curr = q.front();
               q.pop();
               
               if(curr->left != NULL)q.push(curr->left);
               if(curr->right != NULL)q.push(curr->right);
               
           }
           v.push_back(curr->data);
       }
       
    }
