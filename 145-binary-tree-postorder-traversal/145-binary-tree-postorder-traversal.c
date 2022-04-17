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

int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    int *arr = (int *)malloc(sizeof(int) * 101);
    struct TreeNode *q;
    int i = 0;

    if (root)
    {
        while (root->left || root->right)
        {
            q = root;
            while (q)
            {
                if (q->left)
                {
                    if (!q->left->left && !q->left->right)
                    {
                        arr[i++] = q->left->val;
                        q->left = NULL;
                    }
                    q = q->left;
                }
                else if (q->right)
                {
                    if (!q->right->left && !q->right->right)
                    {
                        arr[i++] = q->right->val;
                        q->right = NULL;
                    }
                    q = q->right;
                }
            }
        }
        arr[i++] = root->val;
    }
    *returnSize = i;
    return (arr);
}