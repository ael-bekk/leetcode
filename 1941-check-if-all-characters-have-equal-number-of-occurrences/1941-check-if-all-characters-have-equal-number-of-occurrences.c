

bool areOccurrencesEqual(char * s)
{
    int *alpha = (int *)malloc(sizeof(int) * 26);
    int i = -1, n = 0;
    memset(alpha, 0, sizeof(int) * 26);
    while (*s)
        alpha[*(s++) - 97]++;
    while (++i < 26)
        if (alpha[i])
        {
            if (!n)
                n = alpha[i];
            else if (alpha[i] != n)
                return (0);
        }
    return (1);
}