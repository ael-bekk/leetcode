

void moveZeroes(int* nums, int numsSize)
{
    int i = 0, j = -1;

    while (++j < numsSize)
        if (nums[j])
        {
            nums[i++] = nums[j];
            if (j + 1 > i)
                nums[j] = 0;
        }
}