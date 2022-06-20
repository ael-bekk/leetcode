void    subset(int i, int* nums, int size, int tl, int *total)
{
    
    if (i >= size)
    {
        *total += tl;
        return (0);
    }
    subset(i + 1, nums, size, tl ^ nums[i], total);
    subset(i + 1, nums, size, tl, total);
}

int subsetXORSum(int* nums, int size)
{
    int k = 0;
    subset(0, nums, size, 0, &k);
    return (k);
}