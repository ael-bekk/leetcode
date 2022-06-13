/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int comp(struct TreeNode* l, struct TreeNode* r)
{
    if (!l && !r)
        return (1);
    if (l && r && l->val == r->val)
        return (comp(l->left, r->right) && comp(r->left, l->right));
    return (0);
}

bool isSymmetric(struct TreeNode* root)
{
    return(comp(root->left, root->right));
}