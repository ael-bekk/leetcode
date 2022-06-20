

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes)
{
    int **arr;
    int i = -1;

    if (matSize * *matColSize != r * c)
    {
        *returnSize = matSize;
        *returnColumnSizes = matColSize;
        return (mat);
    }
    
    arr = (int **)malloc(sizeof(int*) * r);
    *returnColumnSizes = (int *)malloc(sizeof(int) * r);
    while (++i < r)
    {
        arr[i] = (int *)malloc(sizeof(int) * c);
        (*returnColumnSizes)[i] = c;
    }
    i = -1;
    while (++i < r * c)
        arr[i / c][i % c] = mat[i / *matColSize][i % *matColSize];
    *returnSize = r;
    return (arr);
}