int uniquePaths(int m, int n)
{
    int **arr = (int **)malloc(sizeof(int*) * m);
    arr[0] = (int *)malloc(sizeof(int) * n);
    int i = 0, j = -1;
    
    while (++j < n)
        arr[0][j] = 1;
    while (++i < m)
    {
        j = -1;
        arr[i] = (int *)malloc(sizeof(int) * n);
        arr[i][++j] = 1;
        while(++j < n)
            arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
    }
    return (arr[--m][--n]);
}