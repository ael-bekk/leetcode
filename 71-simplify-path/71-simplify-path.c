

char * simplifyPath(char * path)
{
    int i = 0, j = -1, k = 0, l;
    char **arr = (char **)malloc(sizeof(char *) * 3000);
    char *res = malloc(3000);
    
    arr[i++] = strtok(path, "/");
    while (arr[i - 1])
    {
        if (!strcmp(arr[i - 1], ".") || (!strcmp(arr[i - 1], "..") && !(i - 1)))
            i--;
        else if (!strcmp(arr[i - 1], ".."))
            i -= 2;
        arr[i++] = strtok(NULL, "/");
    }
    arr[--i] = NULL;
    while (arr[++j])
    {
        l = -1;
        res[k++] = '/';
        while (arr[j][++l])
            res[k++] = arr[j][l];
    }
    if (!k)
        res[k++] = '/';
    res[k++] = 0;
    return (res);
}