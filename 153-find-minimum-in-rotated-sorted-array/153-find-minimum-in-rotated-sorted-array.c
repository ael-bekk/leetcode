

int findMin(int* nums, int numsSize){
    int l = 0, r = numsSize - 1, mid;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (r - l == 1)
            return ((nums[r] > nums[l]) ? nums[l] : nums[r]);
        if (nums[mid] > nums[l] && nums[mid] > nums[r])
            l = mid;
        else
            r = mid;    
    }
    return (nums[r]);
}