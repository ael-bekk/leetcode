/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void fill(struct TreeNode* root, int** arr, int *i)
{
    int *arry = *arr;

    if (root->left)
        fill(root->left, &arry, i);
    if (root)
        arry[(*i)++] = root->val;
    if (root->right)
        fill(root->right, &arry, i);
}


int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int *arr = (int *)malloc(sizeof(int) * 101);
    int lent = 0;

    if (!root)
        *returnSize = lent;
    else
    {
        fill(root, &arr, &lent);
        *returnSize = lent;
    }
    return (arr);
}