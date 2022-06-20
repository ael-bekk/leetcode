

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* sortArrayByParityII(int* nums, int numsSize, int* returnSize)
{
    int i = 0, j = 1, tmp;

    while (i < numsSize && j < numsSize)
    {
        if (!(nums[i] % 2))
            i += 2;
        else if (nums[j] % 2)
            j += 2;
        else
        {
            tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
    }
    *returnSize = numsSize;
    return (nums);
}