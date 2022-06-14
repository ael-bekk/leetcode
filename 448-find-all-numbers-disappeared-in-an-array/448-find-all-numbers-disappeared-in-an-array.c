

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize)
{
    int arr[numsSize + 1];
    int i, j;

    bzero(arr, sizeof(arr));
    i = -1;
    while (++i < numsSize)
        if (!arr[nums[i]])
            arr[nums[i]]++;
    j = i = 0;
    while(++i <= numsSize)
        if (!arr[i])
            nums[j++] = i;
    *returnSize = j;
    return (nums);
}