/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
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
    int *arr = (int *)malloc(sizeof(int) * 10000);
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

bool isValidBST(struct TreeNode* root)
{
    int s, *arr = inorderTraversal(root, &s);
    
    while (--s > 0)
        if (arr[s - 1] >= arr[s])
            return (false);
    return (true);
}