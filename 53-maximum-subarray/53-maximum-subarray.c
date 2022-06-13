#define MAX(X, Y) ((X > Y) ? X : Y)

int maxSubArray(int* nums, int numsSize)
{
    int i = -1, c = 0, s = nums[0];

    while (++i < numsSize)
    {
        c = MAX(c + nums[i], nums[i]);
        s = MAX(c, s);
    }
    return (s);
}