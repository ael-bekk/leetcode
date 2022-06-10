#define MAX(X,Y) ((X > Y) ? X : Y)
#include <stdlib.h>

int ft_bigpalindrome(char * s, int length, int *c)
{
    int i = -1, count = 0, max = 0;
    int l, r;

    while (s[++i] && max + i < length)
    {
        count = 0;
        l = i + 1;
        r = i - 1;
        while (--l >= 0 && ++r < length && s[l] == s[r])
            count++;
        if (s[++l] == '.')
            count--;
        *c = (count > max) ? i : *c;
        max = MAX(count, max);
    }
    return (max - 1);
}

char * longestPalindrome(char * s)
{
    int i = -1, l;
    int length = -1, c = 0;
    int big = 0;
    char *pal, *str;
    
    while (s[++length]);
    str = (char *)malloc(sizeof(char) * (length * 2));
    while (++i < length * 2 - 1)
        if (i % 2)
            str[i] = '.';
        else
            str[i] = s[i / 2];
    str[i] = '\0';
    big = ft_bigpalindrome(str, length * 2 - 1, &c);
    pal = (char *)malloc(sizeof(char) * (big + 2));
    l = c - big - 1;
    i = 0;
    while (++l <= c + big)
    {
        if (str[l] != '.')
            pal[i++] = str[l++];
    }
    pal[i] = '\0';
    return (pal);
}