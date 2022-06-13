

int singleNumber(int* nums, int s)
{
    int i = 0;
    while (s--)
        i ^= nums[s];
    return (i);
}