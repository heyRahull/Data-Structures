void solve(vector<int> &ans, Node *root, int k)
{
    if(root == NULL)return;
    if(k==0) ans.push_back(root->data);
    else
    {
        solve(ans,root->left,k-1);
        solve(ans,root->right,k-1);
    }
}

vector<int> Kdistance(struct Node *root, int k)
{
  // Your code here
  vector<int>v;
  solve(v,root,k);
  
  return v;
}
