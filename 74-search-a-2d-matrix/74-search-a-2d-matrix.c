int bin_s(int* matrix, int l, int r, int target)
{
    int midle;
    
    midle = (l + r) / 2;
    if (matrix[midle] == target)
        return (1);
    if (r <= l)
        return (0);
    if (matrix[midle] > target)
        return (bin_s(matrix, l, midle - 1, target));
    return (bin_s(matrix, midle + 1, r, target));
}




int bin_search(int** matrix, int l, int r, int target)
{
    int midle;
    if (r <= l)
        return (l);
    midle = (l + r + 1) / 2;
    if (matrix[midle][0] == target)
        return (midle);
    if (matrix[midle][0] > target)
        return (bin_search(matrix, l, midle - 1, target));
    return (bin_search(matrix, midle, r, target));
    
}

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    int res;

    res = bin_search(matrix, 0, matrixSize - 1, target);
    return (bin_s(matrix[res], 0, *matrixColSize - 1, target));
}