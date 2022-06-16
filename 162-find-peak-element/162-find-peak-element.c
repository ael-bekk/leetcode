

int findPeakElement(int* nums, int numsSize)
{
    int l = 0, r = numsSize - 1, mid;

    while (l < r)
    {
        mid = (l + r) / 2;
        if (mid && mid + 1 < numsSize && nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            return (mid);
        if (mid && nums[mid] < nums[mid - 1])
            r = mid - 1;
        else if (mid + 1 < numsSize && nums[mid] < nums[mid + 1])
            l = mid + 1;
        else if (!mid || mid + 1 == numsSize)
            return (mid); 
    }
    return (l);
}