int numDistinct(char *s, char *t)
{
    int t_len = -1, i = -1, j;
    unsigned long long *d;
    
    while (t[++t_len]);
    d = (unsigned long long *)malloc(sizeof(unsigned long long) * (t_len + 1));
    memset(d, 0, (t_len + 1) * sizeof(unsigned long long));
    d[0] = 1;
    i = -1;
    while (s[++i])
    {
        j = t_len + 1;
        while (--j > 0)
            if (s[i] == t[j - 1])
                d[j] += d[j - 1];       
    }
    return d[t_len];
}