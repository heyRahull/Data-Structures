 //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
        
    	// Code here
    	vector<int>ans;
    	queue<Node *>q;
    	if(root == NULL)return ans;
    	q.push(root);
    	int f=1;
    	
    	while(q.empty()==false)
    	{
    	    vector<int>v;
    	    int count = q.size();
    	    
    	    while(count--)
    	    {
    	        Node *curr = q.front();
    	        v.push_back(curr->data);
    	        q.pop();
    	        
    	        
    	        if(curr->left!=NULL)q.push(curr->left);
    	        if(curr->right!=NULL)q.push(curr->right);
    	    }
    	    
    	    if(f%2==0)
    	    reverse(v.begin(),v.end());
    	    
    	    for(int i=0;i<v.size();i++)
    	        ans.push_back(v[i]);
    	        
    	   f=!f;
    	    
    	}
    	return ans;
    }
