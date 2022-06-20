#define MAX(X,Y) ((X > Y) ? X : Y)

int maxTurbulenceSize(int* arr, int arrSize)
{
    int count = 1;
    int k = 0;
    int i = 0;
    bool ent;

    while (i < arrSize - 1)
    {
        if (arr[i] == arr[i + 1])
            i++;
        else
        {
            ent = arr[i] > arr[i + 1];
            k = 1;
            while (i < arrSize - 1 && ((!ent && arr[i] < arr[i + 1]) || (ent && arr[i] > arr[i + 1])))
           {
                k++;
                ent = !ent;
                i++;
            }
        }
        count = MAX(count, k);
    }
    return (count);
}