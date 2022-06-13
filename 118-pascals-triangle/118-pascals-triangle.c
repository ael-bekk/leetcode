

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes)
{
    int **arr;
    int i = -1, j;

    arr = (int **)malloc(sizeof(int *) * numRows);
    *returnColumnSizes = (int *)malloc(sizeof(int) * numRows);

    while (++i < numRows)
    {
        arr[i] = (int *)malloc(sizeof(int) * (i + 1));
        (*returnColumnSizes)[i] = i + 1;
        j = -1;
        while (++j < i + 1)
        {
            arr[i][j] = 1;
            while (++j < i)
                arr[i][j] = arr[i- 1][j - 1] + arr[i - 1][j];
            arr[i][i] = 1;
        }
    }
    *returnSize = numRows;
    return (arr);
}