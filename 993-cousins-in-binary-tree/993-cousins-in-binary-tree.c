/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void Cousins(struct TreeNode* root, int l, int *i, int *j, int *x, int *y)
{
    if (!root)
        return ;
    if (root->val == *x)
    {
        *i = l;
        return ;
    }
    if (root->val == *y)
    {
        *j = l;
        return ;
    }
    if ((root->left && root->right) && 
        ((root->left->val == *x && root->right->val == *y) 
         || (root->left->val == *y && root->right->val == *x)))
        return ;
    
    Cousins(root->left, l + 1, i, j, x, y);
    Cousins(root->right, l + 1, i, j, x, y);
}


bool isCousins(struct TreeNode* root, int x, int y)
{
    int i = -1, j = -1;
    Cousins(root, 0, &i, &j, &x, &y);
    return (i == j && i != -1);
}