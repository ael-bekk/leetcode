

int findNumbers(int* nums, int numsSize)
{
    int i = -1, count = 0;

    while (++i < numsSize)
        if ((nums[i] > 9 && nums[i] < 100) 
            || (nums[i] > 999 && nums[i] < 10000)
            || nums[i] == 100000)
            count++;
    return (count);
}