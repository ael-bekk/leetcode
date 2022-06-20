void merge(int **arr, int **l, int sl, int **r, int sr)
{
    int i = 0, j = 0, k = 0;
    
    while (i < sl && j < sr)
        arr[k++] = (l[i][0] < r[j][0]) ? r[j++] : l[i++];
    while (i < sl)
        arr[k++] = l[i++];
    while (j < sr)
        arr[k++] = r[j++];
}

void sorte(int **arr, int s)
{
    if (s == 1)
        return;
    int **l = (int **)malloc(sizeof(int*) * (s + 1)/2);
    int **r = (int **)malloc(sizeof(int*) * (s + 1)/2);
    int sl = 0, sr = 0, k = 0;
    
    while (k < s / 2)
    {
        l[sl] = (int *)malloc(sizeof(int) * 2);
        l[sl++] = arr[k++];
    }
    while (k < s)
    {
        r[sr] = (int *)malloc(sizeof(int) * 2);
        r[sr++] = arr[k++];
    }
    sorte(l, sl);
    sorte(r, sr);
    merge(arr, l, sl, r, sr);
}

char * frequencySort(char * s)
{
    int **Aa1 = (int **)malloc(sizeof(int*) * 128);
    int i = -1, j = 0, k, l = 0;

    while (++i < 128)
    {
        Aa1[i] = (int *)malloc(sizeof(int) * 2);
        Aa1[i][0] =  Aa1[i][1] = 0;
    }
    i = -1;
    while (s[++i])
    {
        Aa1[s[i]][0]++;
        Aa1[s[i]][1] = s[i];
    }
    i = -1;
    while (++i < 128)
        if (Aa1[i][0])
            Aa1[j++] = Aa1[i];
    
    sorte(Aa1, j);
    i = -1;
    while (++i < j)
    {
        k = -1;
        while (++k < Aa1[i][0])
            s[l++] = Aa1[i][1];
    }   
    return (s);
}