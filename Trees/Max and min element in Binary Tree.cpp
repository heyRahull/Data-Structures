class Solution
{
public:
    int findMax(Node *root)
    {
        //code here
        if(root == NULL)
        return INT_MIN;
        else
        return max(root->data, max(findMax(root->left),findMax(root->right)));
    }
    int findMin(Node *root)
    {
        //code here
        if(root == NULL)
        return INT_MAX;
        else
        return min(root->data, min(findMin(root->left),findMin(root->right)));
    }
};
