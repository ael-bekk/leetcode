

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmpfunc (const void * a, const void * b) {
    if (*(int*)a > *(int*)b)
        return (1);
    if (*(int*)a > *(int*)b)
        return (0);
   return (-1);
}

int* singleNumber(int* nums, int numsSize, int* returnSize)
{
    int *two = (int *)malloc(4 * 2);
    int i = 0;
    
    
    
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    while (++i < numsSize)
        if (nums[i] != nums[i - 1])
        {
            two[0] = nums[i - 1];
            i = numsSize;
        }
        else
            i++;
    while (--numsSize > 0)
        if (nums[numsSize] != nums[numsSize - 1])
        {
            two[1] = nums[numsSize];
            numsSize = 0;
        }
        else
            numsSize--;
    *returnSize = 2;
    return two;
}