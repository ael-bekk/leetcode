#define MAX(X,Y) ((X > Y) ? X : Y)
#define MIN(X,Y) ((X < Y) ? X : Y)

int jump(int* nums, int numsSize)
{
    int i, jump = 0, r = 0, l = 0, largest;

    while (r < numsSize)
    {
        jump += (r != 0);
        i = r - 1;
        largest = 0;
        while (++i <= l)
            largest = MAX(largest, i + nums[i]);
        r = l + 1;
        l = MIN(largest, numsSize - 1);
    }
    return (jump);
}