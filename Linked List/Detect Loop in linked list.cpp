 bool detectLoop(Node* head)
    {
        // your code here
        Node *low = head;
        Node *high = head;
        
        if(!head)return false;
        
        while(high!=NULL && high->next!=NULL)
        {
            low = low->next;
            high = high->next->next;
            
            if(low == high)
            return true;
        }
        return false;
    }
