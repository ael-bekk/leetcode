#define MAX(X,Y) ((X > Y) ? X : Y)
#define MIN(X,Y) ((X < Y) ? X : Y)
int maxSubarraySumCircular(int* nums, int numsSize)
{
    int i = -1, sum1 = 0, maxsum = nums[0], sum2 = 0, minsum = nums[0], max = nums[0], tot = 0;

    while (++i < numsSize)
    {
        sum1 = MAX(sum1 + nums[i], nums[i]);
        maxsum = MAX(sum1, maxsum);
        sum2 = MIN(sum2 + nums[i], nums[i]);
        minsum = MIN(sum2, minsum);
        max = MAX(max, nums[i]);
        tot += nums[i]; 
    }
    if (max < 0)
        return (max);
    return (MAX(maxsum, tot - minsum));
}