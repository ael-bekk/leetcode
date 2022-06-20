

void duplicateZeros(int* arr, int arrSize)
{
    int i = 0, count = 0, j = 0;
    int *tab;

    tab = (int *)malloc(sizeof(int) * arrSize);
    while (i < arrSize)
        tab[j++] = arr[i++];
    j = i = 0;
    while (j < arrSize)
    {
        arr[j++] = tab[i];
        if (!tab[i] && j < arrSize)
            arr[j++] = tab[i];
        i++;
    }
}