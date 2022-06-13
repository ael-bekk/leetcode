

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize)
{
    int tmp[34] = {0};
    int *arr;
    int i = -1, j;

    arr = malloc(sizeof(int) * (rowIndex + 1));
    while (++i < rowIndex + 1)
    {
        j = 0;
        while (++j < i)
            arr[j] = tmp[j - 1] + tmp[j];
        arr[i] = 1;
        j = -1;
        while (++j <= i)
            tmp[j] = arr[j];
    }
    *returnSize = rowIndex + 1;
    return (arr);
}