

int removeElement(int* nums, int numsSize, int val){
    int i;
    int j;

    j = -1;
    i = -1;
    while (++i < numsSize)
        if (nums[i] != val)
            nums[++j] = nums[i];
    return (j + 1);
}