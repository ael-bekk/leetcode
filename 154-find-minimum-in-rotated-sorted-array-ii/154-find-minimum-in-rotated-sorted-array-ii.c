

int findMin(int* nums, int k)
{
   int i = 0;

    while (++i < k)
        if (nums[i - 1] > nums[i])
            return (nums[i]);
    return (nums[0]);

}