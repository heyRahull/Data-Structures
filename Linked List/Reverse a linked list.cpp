struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        
        Node *curr = head;
        Node *prev = NULL;
        Node *nex;
        
        while(curr!=NULL)
        {
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        head = prev;
        return head;
    }
