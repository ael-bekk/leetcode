#include <stdlib.h>

int ft_size(char** strs, int strsSize)
{
    int     i;
    int     j;
    int     boo;
    char    prefix;
    
    i = 0;
    boo = 1;
    while (boo)
    {
        prefix = strs[0][i];
        j = 1;
        while (j < strsSize && strs[j][i] && prefix == strs[j][i])
            j++;
        if (j != strsSize)
            boo = 0;
        i++;
    }
    return (i);
}

char * longestCommonPrefix(char ** strs, int strsSize){
    int     i;
    int     j;
    char    *prefix;
    int     boo;


    if (strsSize == 1)
        return(strs[0]);
    prefix = (char *)malloc(sizeof(char) * ft_size(strs, strsSize) + 1);
    i = 0;
    boo = 1;
    while (boo)
    {
        prefix[i] = strs[0][i];
        j = 1;
        while (j < strsSize && strs[j][i] && prefix[i] == strs[j][i])
            j++;
        if (j != strsSize)
            break ;
        i++;
    }
    prefix[i] = '\0';
    return (prefix);
}