

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
    int *arr = (int *)malloc(sizeof(int) * 2);
    int i = 0;

    numbersSize--;
    while (i < numbersSize)
        if (numbers[i] + numbers[numbersSize] > target)
            numbersSize--;
        else if (numbers[i] + numbers[numbersSize] < target)
            i++;
        else
        {
            arr[0] = i + 1;
            arr[1] = numbersSize + 1;
            *returnSize = 2;
            return (arr);
        }
    *returnSize = 0;
    return (arr);
}