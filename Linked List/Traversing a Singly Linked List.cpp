void printLL(Node *head)
{
 Node *curr = head;
  while(curr->next!=NULL)
  {
    cout(curr->data)<<" ";
    curr = curr->next;
  }
}
