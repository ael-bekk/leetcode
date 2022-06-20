/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* insertIntoBST(struct TreeNode* root, int val)
{
    struct TreeNode* r = root;
    struct TreeNode* new = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    new->val = val;
    new->left = NULL;
    new->right = NULL;

    while (r)
        if (r->val > val && r->left)
            r = r->left;
        else if (r->val < val && r->right)
            r = r->right;
        else 
        {
            if (r->val > val && !r->left)
                r->left = new;
            else
                r->right = new;
            return (root);
        }
    return (new);
}