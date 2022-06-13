/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int countNodes(struct TreeNode* root)
{
    struct TreeNode *q = root, *p = root;
    int l = 0, r = 0;
    if (!root)
        return (0);
    
    while (q || p)
    {
        if (q)
            q = q->left,
            l++;
        if (p)
            p = p->right,
            r++;
    }
    if (l == r)
        return ((1 << l) - 1);
    return (1 + countNodes(root->left) + countNodes(root->right));
}