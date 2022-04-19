bool isValid(char * s)
{
    char *head = malloc(strlen(s));
    int i = 0, j = 0;
    while (s[i])
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            head[j++] = s[i];
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
                if (j && ((head[j - 1] == '(' && s[i] == ')') || (head[j - 1] == '{' && s[i] == '}') || (head[j - 1] == '[' && s[i] == ']')))
                    j--;
        else
            return (false);
        i++;
    }
    if (j)
        return (false);
    return (true);
}