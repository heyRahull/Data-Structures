 vector<int> levelOrder(Node* node)
    {
      //Your code here
      vector<int> ans;
      if(node == NULL) return ans;
      queue<Node *>q;
      q.push(node);
      while(q.empty() == false )
      {
          Node *curr = q.front();
          q.pop();
          ans.push_back(curr->data);
          if(curr->left!=NULL)
          q.push(curr->left);
          if(curr->right!=NULL)
          q.push(curr->right);
      }
      return ans;
    }
