

int countKDifference(int* nums, int numsSize, int k){
    int i = -1, j, count = 0;

    while (++i < numsSize - 1)
    {
        j = i;
        while (++j < numsSize)
            if ((nums[i] - nums[j] == k) || (nums[i] - nums[j] == -k))
                count++;
    }
    return count;
}