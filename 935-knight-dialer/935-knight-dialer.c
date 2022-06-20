
int knightDialer(int n)
{
    int i = 0, j, k, count = 0;
    int *arr[] = {(int[]){4, 6, -1},
                    (int[]){6, 8, -1},
                    (int[]){7, 9, -1},
                    (int[]){4, 8, -1},
                    (int[]){0, 3, 9, -1},
                    (int[]){-1},
                    (int[]){0, 1, 7, -1},
                    (int[]){2, 6, -1},
                    (int[]){1, 3, -1},
                    (int[]){2, 4, -1}};
    int prev[10];
    int dp[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    while (++i < n)
    {
        j = -1;
        while (++j < 10)
            prev[j] = dp[j];
        j = -1;
        while (++j < 10)
        {
            k = -1;
            dp[j] = 0;
            while (arr[j][++k] != -1)
                dp[j] = (dp[j] + prev[arr[j][k]])  % 1000000007;
        }
    }
    i = -1;
    while (++i < 9)
        dp[i + 1] = (dp[i + 1] + dp[i]) % 1000000007;
    return (dp[9] % 1000000007);
}