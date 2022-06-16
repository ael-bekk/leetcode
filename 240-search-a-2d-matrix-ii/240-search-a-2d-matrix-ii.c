bool searchMatrix(int** matrix, int msize, int* mCsize, int target)
{
    int i = msize - 1, j = 0;

    while ((i || j < mCsize[i] - 1) && matrix[i][j] != target)
        if (j < mCsize[i] - 1 && matrix[i][j] < target)
            j++;
        else if (i && matrix[i][j] > target)
            i--;
        else
            break ;
    return (matrix[i][j] == target);
}