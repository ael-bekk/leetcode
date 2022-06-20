/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int check_nodes(struct TreeNode* root, int *diameter)
{
    int l = 0, r = 0;

    if (root->left)
        l += 1 + check_nodes(root->left, diameter);
    if (root->right)
        r += 1 + check_nodes(root->right, diameter);
    if (*diameter < l + r)
        *diameter = l + r;
    return ((l > r) ? l : r);
}

int diameterOfBinaryTree(struct TreeNode* root)
{
    int diameter = 0;
    check_nodes(root, &diameter);
    return (diameter);
}