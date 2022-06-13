
int searchInsert(int* nums, int numsSize, int target)
{
    int mid, min = 0, max = numsSize - 1;
    
    while (min <= max)
    {   
        mid = (max + min) / 2;
        if (target == nums[mid])
            return (mid);
        else if (target < nums[mid])
            max = mid - 1;
        else
            min = mid + 1;
    }
    return (min);
}
