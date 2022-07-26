int getSize(Node* node)
{
   // Your code here
   if(node == NULL) return 0;
   else 
   return getSize(node->left)+getSize(node->right)+1;
}
