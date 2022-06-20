int ft_strlent(char * s)
{
    int i = 0;
    
    while (s[i]) i++;
    return (i);
}

int not_letter(char c)
{
    if ((c < 65 || c > 90) && (c < 97 || c > 122))
        return (1);
    return (0);
}

char * reverseOnlyLetters(char * s)
{
    int head, end;
    char temp;

    head = 0;
    end = ft_strlent(s) - 1;
    while (head < end)
    {
        while (not_letter(s[head]) && head < end) head++;
        while (not_letter(s[end]) && head < end) end--;
        temp = s[head];
        s[head++] = s[end];
        s[end--] = temp;
    }
    return (s);
}