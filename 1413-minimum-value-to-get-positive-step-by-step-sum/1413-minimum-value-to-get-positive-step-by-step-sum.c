

int minStartValue(int* nums, int s)
{
    int start = 1, sum = 1;
    int i = -1, l;

    while (++i < s)
    {
        if (sum + nums[i] < 1)
        {
            start += -(sum + nums[i]) + 1;
            l = -(sum + nums[i]) + 1;
        }
        else
            l = 0;
        sum += nums[i] + l;
    }
    return (start);
}