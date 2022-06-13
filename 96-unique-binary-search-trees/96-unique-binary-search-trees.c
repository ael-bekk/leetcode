

int numTrees(int n)
{
    int i = 1;
    int j;
    int arr[n + 1];
    
    arr[0] = arr[1] = 1;
    while (++i <= n)
    {
        arr[i] = 0;
        j = -1;
        while (++j < i)
            arr[i] += arr[i - j - 1] * arr[j];
    }
    return (arr[n]);
}