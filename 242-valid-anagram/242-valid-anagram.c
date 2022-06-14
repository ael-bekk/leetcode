

bool isAnagram(char * s, char * t)
{
    int *alp = (int *)malloc(sizeof(int) * 26);
    int i = 0, j = 0;

    memset(alp, 0, sizeof(int) * 26);
    while (s[i])
        alp[s[i++] - 97]++;
    while (t[j])
        alp[t[j++] - 97]--;
    i = -1;
    while (++i < 26)
        if (alp[i])
            return (0);
    return (1);
}