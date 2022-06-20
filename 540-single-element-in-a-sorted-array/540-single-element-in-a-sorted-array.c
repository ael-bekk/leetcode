

int singleNonDuplicate(int* nums, int s)
{
    if (!s)
        return (0);
    return (nums[0] ^ singleNonDuplicate(nums + 1, s - 1));
}