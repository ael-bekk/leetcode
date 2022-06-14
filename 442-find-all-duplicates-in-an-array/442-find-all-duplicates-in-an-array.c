

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* findDuplicates(int* nums, int numsSize, int* returnSize)
{
    int i = -1, j = 0;
    int *arr = (int *)malloc(sizeof(int) * numsSize);

    while (++i < numsSize)
    {
        nums[abs(nums[i]) - 1] *= -1;
        if (nums[abs(nums[i]) - 1] > 0)
            arr[j++] = abs(nums[i]);
    }
        
    *returnSize = j;
    return (arr);
}