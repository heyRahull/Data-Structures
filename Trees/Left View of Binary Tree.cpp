vector<int> leftView(Node *root)
{
   // Your code here
  
   vector<int>v;
   queue<Node *>q;
    if(root == NULL)return v;
   q.push(root);
   while(q.empty()==false)
   {
       int count = q.size();
       for(int i=0;i<count;i++)
       {
           Node *curr = q.front();
           q.pop();
           if(i==0)
           v.push_back(curr->data);
           if(curr->left != NULL)
           q.push(curr->left);
           if(curr->right != NULL)
           q.push(curr->right);
       }
   }
}
