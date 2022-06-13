int ft_strlent(char *s1, char *s2)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (s1[i] && s2[i])
        i++;
    if (s1[i])
        while (s1[i + j])
            j++;
    else if (s2[i])
        while (s2[i + j])
            j++;
    return (j);
}

int strStr(char * haystack, char * needle){
    int i;
    int j;
    int comlent;

    i = 0;
    if (!needle[i])
        return (0);
    comlent = ft_strlent(haystack, needle);
    while (haystack[i] && comlent >= 0)
    {
        j = 0;
        while (haystack[i + j] && needle[j] && needle[j] == haystack[i + j])
            j++;
        if (!needle[j])
            return (i);
        i++;
        comlent--;
    }
    return (-1);
}