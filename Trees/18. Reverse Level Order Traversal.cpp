vector<int> reverseLevelOrder(Node *root)
{
    // code here
   
    vector<int>v;
     if(root== NULL)return v;
    queue<Node *>q;
    q.push(root);
    
    while(q.empty() == false)
    {
        Node *curr = q.front();
        q.pop();
        v.push_back(curr->data);
        
        if(curr->right != NULL)q.push(curr->right);
        if(curr->left != NULL)q.push(curr->left);
        
    }
    reverse(v.begin(),v.end());
    return v;
}
