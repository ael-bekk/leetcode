void strrev(char * s, int start, int end)
{
    char tmp;
    
    while (++start < --end)
    {
        tmp = s[start];
        s[start] = s[end];
        s[end] = tmp;
    }
}

char * reverseWords(char * s)
{
    int i = 0, j = 0, l;

    while (s[i])
    {
        if (j)
            s[j++] = ' ';
        l = j;
        while (s[i] && s[i] == ' ')
            i++;
        while (s[i] && s[i] != ' ')
            s[j++] = s[i++];
        strrev(s, l - 1, j);
        while (s[i] && s[i] == ' ')
            i++;
    }
    s[j] = '\0';
    strrev(s, -1, j);
    return (s);
}