

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* sortedSquares(int* nums, int numsSize, int* returnSize){
    int *arr = (int *)malloc(sizeof(int) * numsSize);
    int i = 0, k = numsSize - 1;
    
    *returnSize = numsSize--;
    while (i <= numsSize)
    {
        if (nums[i] * nums[i] > nums[numsSize] * nums[numsSize])
            arr[k--] = nums[i] * nums[i++];
        else
            arr[k--] = nums[numsSize] * nums[numsSize--];
    }
    return (arr);
}