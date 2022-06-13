

bool canJump(int* nums, int numsSize)
{
    int i = -1, jump = 0;

    while (++i < numsSize && (jump || nums[i]))
        jump = (nums[i] > jump) ? --nums[i] : --jump;
    return (i + 1 >= numsSize-- || !numsSize);
}