Node *insertend(Node *head, int x)
{
  Node * temp = new Node(x);
  if(head == NULL)
    return temp;
  
  Node *curr = head;
  while(currr->next!=NULL)
    curr = curr->next;
  
  curr->next = temp;
  return head;
}
