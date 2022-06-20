/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


void returnlevelsum(struct TreeNode* root, int i, int *arr, int *level)
{
    if (!root)
        return ;
    arr[i] += root->val;
    (*level) = (*level < i) ? i : *level;
    returnlevelsum(root->left, i + 1, arr, level);
    returnlevelsum(root->right, i + 1, arr, level);
}


int maxLevelSum(struct TreeNode* root)
{
    
    int i;
    int level = 0;
    int sum;
    int arr[10000];

    memset(arr, 0, sizeof(arr));
    i = 0;
    returnlevelsum(root, 0, arr, &level);
    sum = 0;
    while (++i <= level) 
        sum = (arr[i] <= arr[sum]) ? sum : i;
    return (sum + 1);
}