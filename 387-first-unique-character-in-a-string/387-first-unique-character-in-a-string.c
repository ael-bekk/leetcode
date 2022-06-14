#include <limits.h>

int firstUniqChar(char * s)
{
    int *alpha = (int *)malloc(sizeof(int) * 26);
    int i = -1, min = INT_MAX;
    
    memset(alpha, -1, sizeof(int) * 26);
    while (s[++i])
    {
        if (alpha[s[i] - 97] == -1)
            alpha[s[i] - 97] = i;
        else
            alpha[s[i] - 97] = -2;
    }
    i = -1;
    while (++i < 26)
    {
        if (alpha[i] >= 0)
            if (min > alpha[i])
                min = alpha[i];
    }
    free(alpha);
    alpha = NULL;
    if (min != INT_MAX)
        return (min);
    return (-1);
}