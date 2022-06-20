
typedef struct parths
{
    char c;
    int  index;
}   parths;

char * minRemoveToMakeValid(char * s)
{
    parths arr[100000];
    int top = 0;
    int i = -1, j = 0, k = 0, l = -1;

    while (s[++l])
    {
        if (s[l] == ')' && top && arr[top - 1].c == '(') top--;
        else if (s[l] == ')' || s[l] == '(')
        {
            arr[top].c = s[l];
            arr[top++].index = l;
        }
    }
    i = -1;
    while (++i < l)
    {
        while (k < top && arr[k].index == i && ++i) ++k;
        s[j++] = s[i];
    }
    s[j] = NULL;
    return (s);
}