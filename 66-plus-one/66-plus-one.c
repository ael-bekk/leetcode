

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    *returnSize = digitsSize;
    while (--digitsSize >= 0)
        if (++digits[digitsSize] < 10)
            return (digits);
        else
            digits[digitsSize] %= 10;
    
    digits = (int *)realloc(digits, sizeof(int) * ++(*returnSize));
    digits[*returnSize - 1] = 0;
    digits[0] = 1;
    return (digits);
}