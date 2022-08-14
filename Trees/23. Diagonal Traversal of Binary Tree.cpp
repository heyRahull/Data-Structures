vector<int> diagonal(Node *root)
{
   // your code here
   vector<int>v;
   queue<Node *>q;
   
   if(root==NULL)return v;
   q.push(root);
   
   
   while(q.empty()==false)
   {
       Node *temp = q.front();
       q.pop();
       
       while(temp!=NULL)
       {
           if(temp->left!=NULL)
           q.push(temp->left);
           v.push_back(temp->data);
           temp = temp ->right;
       }
   }
   return v;
}
