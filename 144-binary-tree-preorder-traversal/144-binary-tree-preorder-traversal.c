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

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    int *arr = (int *)malloc(sizeof(int) * 101);
    struct TreeNode **bin = (int *)malloc(sizeof(int) * 20);
    int i = 0, j = 0;

    bin[++j] = root;
    while (root || j)
    {
        root = bin[j--];
        while (root)
        {
            if (root->right)
                bin[++j] = root->right;
            arr[i++] = root->val;
            root = root->left;
        }
    }
    free(bin);
    *returnSize = i;
    return (arr);
}