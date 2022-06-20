

int findMaxConsecutiveOnes(int* nums, int numsSize)
{
    int i = 0, count, max = 0;

    while (i < numsSize)
    {
        count = 0;
        while(i < numsSize && nums[i++] == 1) count++;
        if (count > max)
            max = count;
    }
    return (max);
}