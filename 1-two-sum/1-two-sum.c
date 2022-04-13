

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i, j, sum, *tab;
    
    *returnSize = 2;
    tab = (int *)malloc(sizeof(int) * 2);
    i = -1;
    while (++i < numsSize - 1)
    {
        sum = nums[i];
        j = i;
        while (++j < numsSize && (sum + nums[j]) != target);
        if (j != numsSize)
        {
            tab[0] = i;
            tab[1] = j;
            return (tab);
        }
    }
    return (tab);
}