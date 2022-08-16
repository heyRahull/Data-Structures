
//Mirror of a Tree :

void mirror(Node* node) {
   if(node == NULL) return;
   mirror(node->left);
   mirror(node->right);
   return swap(node->left,node->right);
   
 }

//Convert binary tree into sum tree

int toSumTree(Node *root)
{
   if(root == NULL) return 0;
   
   int a =  toSumTree(root->left);
   int b = toSumTree(root->right);
   int x = root -> data;
   root -> data = a+b;
   return a+b+x;
}

//
