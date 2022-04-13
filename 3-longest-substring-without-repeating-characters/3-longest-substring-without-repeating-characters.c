#define MAX(X,Y) ((X > Y) ? X : Y)

int lengthOfLongestSubstring(char * s)
{
    int max = 0;
    char arr[127] = "\0";
    char *start = s;
    
    while (*s)
        if (!arr[*s])
        {
            arr[*s] = *s;
            s++;
            max = MAX(max, s - start);
        }
        else
            arr[*(start++)] = '\0';
    return (max);
}