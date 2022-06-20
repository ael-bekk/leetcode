
int bin_search(int *arr, int l, int r, int target)
{
    int middl = (l + r) / 2;
    if (r < l)
        return (-1);
    if (arr[middl] == target)
        return (middl);
    if (arr[middl] > target)
        return(bin_search(arr, l, middl - 1, target));
    return (bin_search(arr, middl + 1, r, target));
}

int search(int* nums, int numsSize, int target)
{
    return (bin_search(nums, 0, numsSize - 1, target));
}