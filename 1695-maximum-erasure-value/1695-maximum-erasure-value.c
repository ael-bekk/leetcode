

int maximumUniqueSubarray(int* nums, int n)
{
    int i = -1, l = 0, r = 0, sum = 0, max = 0;
    int arr[10001] = {0};

    while (++i < n)
        if (!arr[nums[i]])
            arr[nums[i]] = 1,
            sum += nums[i],
            max = (max > sum) ? max : sum,
            r++;
        else if (l < r)
            sum -= nums[l],
            arr[nums[l++]] = 0,
            i--;
    return (max);
}