void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        
        Node *low = head;
        Node *high = head;
        
        while(low!=NULL && high!=NULL && high->next!=NULL)
        {
            low = low->next;
            high = high->next->next;
            if(low==high)
            break;
        }
        
        if(low==head && high==head)
        {
            while(high->next!=low)
            high = high->next;
            
            high->next == NULL;
        }
        else
        {
            low = head;
            while(low->next!=high->next)
            {
                low = low->next;
                high = high->next;
            }
            high->next = NULL;
        }
    }
