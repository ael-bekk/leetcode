char *reverseString(char* s, int sSize)
{
    int i = -1;

    while (++i < --sSize)
    {
        if (s[i] == '(')
            s[i] = ')';
        else
            s[i] = '(';
        if (s[sSize] == '(')
            s[sSize] = ')';
        else
            s[sSize] = '(';
        s[sSize] ^= s[i] ^= s[sSize] ^= s[i];
    }
    if (i == sSize)
    {
        if (s[i] == '(')
            s[i] = ')';
        else
            s[i] = '(';
    }
    return (s);
}

int longest(char * s)
{
    int lent= strlen(s), max = 0;
    int i = 0, j = 0, count = 0;
    char *head = malloc(strlen(s));

    while (s[i])
    {
        if (s[i] == '(')
            head[j++] = s[i];
        else if (s[i] == ')' && j && head[j - 1] == '(' && s[i] == ')')
            j--;
        else
        {
            j = 0;
            count = i + 1;
        }
        if (!j && i - count + 1 > max)
                max = i - count + 1;
        i++;
    }
    return (max);
}

int longestValidParentheses(char * s)
{
    int a = longest(s);
    printf("%s\n", s);
    int b = longest(reverseString(s, strlen(s)));
    printf("%s\n", s);
    return((a > b) ? a : b);
}