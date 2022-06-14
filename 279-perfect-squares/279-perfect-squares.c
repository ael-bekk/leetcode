int dp[10001] = {0};


int numSquares(int n)
{
    int i = 0, j;
    
    if (dp[n])
        return (dp[n]);
    
    while (++i <= n)
    {
        j = 0;
        dp[i] = i;
        while (++j * j <= i)
            if (dp[i] > 1 + dp[i - j * j])
                dp[i] = 1 + dp[i - j * j];
    }
    return (dp[n]);
}