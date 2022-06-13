
void revers(int *arr,int i,int numsSize)
{
    int tmp;

    while (++i < --numsSize)
    {
        tmp = arr[i];
        arr[i] = arr[numsSize];
        arr[numsSize] = tmp;
    }
}

void rotate(int* nums, int numsSize, int k)
{
    revers(nums, -1, numsSize);
    revers(nums, -1, k % numsSize);
    revers(nums, (k % numsSize) - 1, numsSize);
}