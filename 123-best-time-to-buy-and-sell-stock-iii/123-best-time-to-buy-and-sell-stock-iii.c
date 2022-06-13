int mem[100001][2];

int check(int *arr, int i, int s, int tr)
{
    if (!tr || i >= s)
        return (0);
    int a = 0, c = 0;
    if (mem[i][tr - 1] != -1)
        return (mem[i][tr - 1]);
    if (i % 2)
    {
        a = arr[i] + check(arr, i + 1, s, tr - 1);
        c = check(arr, i + 2, s, tr);
    }
    else
    {
        a = -arr[i] + check(arr, i + 1, s, tr);
        c = check(arr, i + 2, s, tr);
    }
    return (mem[i][tr - 1] = (c > a)? c : a);
}

int maxProfit(int* prices, int s)
{
    int i = 0, j = 0; 
    memset(mem, -1, sizeof(mem));
    while (i + 1 < s)
    {
        while (++i < s && prices[i - 1] >= prices[i]);
        prices[j++] = prices[i - 1];
        while (++i < s && prices[i - 1] <= prices[i]);
        prices[j++] = (i <= s) ? prices[i - 1] : 0;    
    }
    
    return (check(prices, 0, j, 2));
}