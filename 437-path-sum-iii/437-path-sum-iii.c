/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int paths(struct TreeNode* root, long long target, bool start)
{
    if (!root)
        return (0);
    int l = paths(root->left, target - root->val, 1) + paths(root->right, target - root->val, 1);
    if (!start)
        l += paths(root->left, target, 0) + paths(root->right, target, 0);
    return ((root->val == target) + l);
}


int pathSum(struct TreeNode* root, int target)
{
    return (paths(root, target, 0));
}