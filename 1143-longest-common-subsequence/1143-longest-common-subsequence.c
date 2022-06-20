#define MAX(X,Y) ((X > Y) ? X : Y)

int longestCommonSubsequence(char * text1, char * text2)
{
    int i = -1, j = -1, len1 = strlen(text1), len2 = strlen(text2);
    int **dp = (int **)malloc(sizeof(int *) * (len1 + 1));
    while (++j <= len1)
    {
        dp[j] = (int *)malloc(sizeof(int) * (len2 + 1));
        bzero(dp[j],sizeof(int) * (len2 + 1));
    }
    while (text1[++i])
    {
        j = -1;
        while (text2[++j])
            if (text1[i] == text2[j])
                dp[i + 1][j + 1] = 1 + dp[i][j];
            else
                dp[i + 1][j + 1] = MAX(dp[i][j + 1], dp[i + 1][j]);
    }
    return (dp[len1][len2]);
}