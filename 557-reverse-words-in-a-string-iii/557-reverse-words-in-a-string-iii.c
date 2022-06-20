void reverseString(char* s, int i, int j)
{
    int tmp;

    while (++i < --j)
    {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

char * reverseWords(char * s)
{
    int i = -1, j;

    while (s[++i])
    {
        if (s[i] != ' ')
        {
            j = i;
            while (s[i] && s[i] != ' ')
                i++;
            reverseString(s , j - 1, i);
            i--;
        }
    }
    return (s);
}