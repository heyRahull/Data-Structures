void mirror(Node* node) {
        // code here
        if(node == NULL)return;
        mirror(node->left);
        mirror(node->right);
        return swap(node->left,node->right);
    }
