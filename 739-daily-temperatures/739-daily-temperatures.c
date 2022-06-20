

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* tem, int s, int* rs)
{
    int arr[s][2];
    int i = -1, j = -1;

    while (++i < s)
    {
        while (j >= 0 && arr[j][1] < tem[i])
        {
            tem[arr[j][0]] = i - arr[j][0];
            j--;
        }
        arr[++j][0] = i;
        arr[j][1] = tem[i];
    }
    while (j >= 0)
        tem[arr[j--][0]] = 0;
    *rs = s;
    return (tem);
}