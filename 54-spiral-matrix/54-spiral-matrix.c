

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
    int *arr;
    int i = 0, j = 0, k = 0;
    int star_j = 1, star_k = 0, end_j = matrixSize , end_k = *matrixColSize;

    *returnSize = matrixSize * *matrixColSize;
    arr = (int *)malloc(sizeof(int) * (*returnSize));
    while (i < *returnSize)
    {
        while (k < end_k && i < *returnSize)
            arr[i++] = matrix[j][k++];
        k--;
        j++;
        while (j < end_j && i < *returnSize)
            arr[i++] = matrix[j++][k];
        j--;
        k--;
        while (k >= star_k && i < *returnSize)
            arr[i++] = matrix[j][k--];
        k++;
        j--;
        while (j >= star_j && i < *returnSize)
            arr[i++] = matrix[j--][k];
        j++;
        k++;
        star_j++;
        star_k++;
        end_j--;
        end_k--;
    }
    return (arr);
}