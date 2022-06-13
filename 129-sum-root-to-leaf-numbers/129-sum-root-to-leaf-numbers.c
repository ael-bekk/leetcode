/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int sumNumbers(struct TreeNode* root)
{
    if (root->left && root->right)
    {
        root->left->val += root->val * 10;
        root->right->val += root->val * 10;
        return (sumNumbers(root->left) + sumNumbers(root->right));
    }
    if (root->left)
    {
        root->left->val += root->val * 10;
        return (sumNumbers(root->left));
    }
    if (root->right)
    {
        root->right->val += root->val * 10;
        return (sumNumbers(root->right));
    }
    return (root->val);
}