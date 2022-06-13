/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void fill(struct TreeNode* root, int*** arr, int s, int *rs, int** c)
{
    if (root)
    {
        if (s + 1 > *rs)
        {
            (*rs)++;
            *arr = (int **)realloc(*arr, *rs * sizeof(int*));
            (*arr)[s] = (int *)malloc(sizeof(int) * 256);
            *c = (int *)realloc(*c, *rs * sizeof(int));
            (*c)[s] = 0;
        }
        (*arr)[s][(*c)[s]++] = root->val;
        if (root->left)
            fill(root->left, arr, s + 1, rs, c);
        if (root->right)
            fill(root->right, arr, s + 1, rs, c);
    }    
}

int** levelOrder(struct TreeNode* root, int* s, int** c)
{
    int **arr = (int **)malloc(sizeof(int*));
    *c = (int *)malloc(sizeof(int));
    *s = 0;
    fill(root, &arr, 0, s, c);
    return (arr);
}