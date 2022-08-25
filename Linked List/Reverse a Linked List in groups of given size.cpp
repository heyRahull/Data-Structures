struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        node *prev = NULL;
        node *curr = head;
        node *nex;
        int c=0;
        
        while(curr!=NULL && c<k)
        {
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
            c++;
        }
        
        if(nex!=NULL)
        {
            head->next = reverse(nex,k); 
        }
        
        return prev;
    }
