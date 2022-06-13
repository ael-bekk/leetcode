

void sortColors(int* nums, int s)
{
    int i = -1, j = 0, tmp;
    
    while (++i < s)
        if (nums[i] != 1)
        {
            tmp = nums[i];
            if (nums[i] == 0)
            {
                nums[i] = nums[j];
                nums[j++] = tmp;
            }
            else
            {
                nums[i--] = nums[--s];
                nums[s] = tmp;
            }
        }
}