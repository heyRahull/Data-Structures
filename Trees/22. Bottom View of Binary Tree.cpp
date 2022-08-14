vector <int> bottomView(Node *root) {
        // Your Code Here
        
        vector<int>v;
        map<int,int>m;
        queue<pair<Node *,int >>q;
        if(root ==NULL) return v ;
        q.push({root,0});
        
        while(q.empty()==false)
        {
            Node *t = q.front().first;
            int h = q.front().second;
            
            q.pop();
            
            m[h] = t->data;;
            
            if(t->left) q.push({t->left,h-1});
            if(t->right) q.push({t->right,h+1});
        }
        
        for(auto x:m)
        v.push_back(x.second);
    }
