void startLoop(Node* head)
{
  Node *low = head;
  Node *high = head;
  
  while(low!=NULL && high!=NULL && high->next!=NULL)
  {
    low = low->next;
    high = high->next;
    if(low==high)
      break;
  }
  
  if(low!=high)
    return NULL;
  
  low = head;
  while(low!= high)
  {
   low = low->next;
    high = high->next;
  }
    return low;
  
}
