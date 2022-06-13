/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root)
{
    int j, k;
    if (!root)
        return (0);
    j = 1 + maxDepth(root->left);
    k = 1 + maxDepth(root->right);
    return ((j > k)? j : k);
}