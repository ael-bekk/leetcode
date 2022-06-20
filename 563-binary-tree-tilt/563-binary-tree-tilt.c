/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int find(struct TreeNode* root, int *sum)
{
    int l = 0, r = 0, res = root->val;
    
    if (!root->left && !root->right)
        return (root->val);
    if (root->left)
        l = find(root->left, sum);
    if (root->right)
        r = find(root->right, sum);
    res += l + r;
    root->val = (r - l >= 0) ? r - l : l - r;
    *sum = *sum + root->val;
    return (res);
}

int findTilt(struct TreeNode* root)
{
    int sum = 0;

    if (!root)
        return (0);
    find(root, &sum);
    return (sum);
}