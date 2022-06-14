/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool check_nodes(struct TreeNode* root, struct TreeNode* p, struct TreeNode** q)
{
    int check = (root == *q || root == p);
    
    if (root->left && check_nodes(root->left, p, q))
        check++;
    if (root->right && check_nodes(root->right, p, q))
        check++;
    if (check == 2)
    {
        *q = root;
        return (!check);
    }
    return (check);
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
    check_nodes(root, p, &q);
    return (q);
}