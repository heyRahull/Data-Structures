Node *insertBegin(Node *head)
{
  Node *temp = new Node(x);
  temp->next = head;
  return temp;
}
