

bool isMatch(char * s, char * p)
{
    if (!*s && !*p)
        return (1);
    if (*p && *(p + 1) && *(p + 1) == '*')
        if (isMatch(s, p + 2))
            return (1);
    if (*s && (*s == *p || *p == '.'))
    {
        if (*(p + 1) == '*')
            return (isMatch(s + 1,p));
        return (isMatch(s + 1,p + 1));
    }
    return (0);
}