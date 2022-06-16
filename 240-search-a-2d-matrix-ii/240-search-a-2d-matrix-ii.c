int bin_s(int* matrix, int l, int r, int target)
{
    int mid;

    while (l <= r)
    {
        mid = (l + r) / 2;
        if (matrix[mid] > target)
            r = mid - 1;
        else if (matrix[mid] < target)
            l = mid + 1;
        else
            return (true);
    }
    return (false);
}

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    while (matrixSize-- && !bin_s(matrix[matrixSize], 0, matrixColSize[matrixSize] - 1, target));
    return (++matrixSize);
}