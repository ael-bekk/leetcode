

int minimumTotal(int** arr, int s, int* c)
{
    while (--s)
        while (--c[s])
            arr[s - 1][c[s] - 1] += (arr[s][c[s]] < arr[s][c[s] - 1]) ? arr[s][c[s]] : arr[s][c[s] - 1];
    return (arr[0][0]);
}