#define CHECK_DIFF(X, Y) ((X == Y || X == -Y) ? 1 : 0)

int map(int **arr, int size, int val1, int val2)
{
    while (--size >= 0)
        if ((val1 == arr[size][0] && val2 == arr[size][1])
            || (val2 == arr[size][0] && val1 == arr[size][1]))
            return (1);
    return (0);
}

int findPairs(int* nums, int size, int k)
{
    int i = -1;
    int j;
    int h = 0;
    int **arr;

    arr = (int **)malloc(sizeof(int *) * size);
    while (++i < size - 1)
    {
        j = i;
        while (++j < size)
            if(CHECK_DIFF(nums[i] - nums[j], k) && !map(arr, h, nums[j], nums[i]))
            {
                arr[h] = (int*)malloc(sizeof(int) * 2);
                arr[h][0] = nums[j];
                arr[h++][1] = nums[i];
            }
    }
    return (h);
}