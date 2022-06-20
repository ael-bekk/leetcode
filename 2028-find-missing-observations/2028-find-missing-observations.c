

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* missingRolls(int* rolls, int rollsSize, int mean, int n, int* returnSize)
{
    int i;
    int *rolls2;
    int sum;
    int rols;

    i = -1;
    sum = 0;
    while (++i < rollsSize)
        sum += rolls[i];
    rolls2 = (int *)malloc(sizeof(int) * n);
    sum = mean * (rollsSize + n) - sum;
    if (sum / n + (sum % n != 0) > 6 || sum / n <= 0)
    {
        *returnSize = 0;
        return (rolls2);
    }
    *returnSize = n;
    i = -1;
    rols = sum % n;
    while (++i < n)
    {
        rolls2[i] = sum / n;
        if (rols)
        {
            rolls2[i]++;
            rols--;
        }
    }
    return (rolls2);
}