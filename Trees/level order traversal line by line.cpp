vector<vector<int>> levelOrder(Node* node)
{
      //Your code here
      vector<int> v;
      vector<vector<int>> ans;
      if(node == NULL) return ans;
      queue<Node *>q;
      q.push(node);
      while(q.empty() == false )
      {
          int count = q.size();
          for(int i=0;i< count; i++ )
          {
          Node *curr = q.front();
          q.pop();
          v.push_back(curr->data);
          if(curr->left!=NULL) q.push(curr->left);
          if(curr->right!=NULL) q.push(curr->right);
          }
          ans.push_back(v);
          v.clear();
      }
      return ans;
    
}
