
int integerReplacement(int n)
{
    int count;

    count = 0;
    while (n != 1)
    {
        if (n % 2 == 0)
            n /= 2;
        else if (n == 2147483647)
        {
            count--;
            n--;
        }
        else if (((n - 1) / 2) % 2 == 0 || n == 3)
            n--;
        else
            n++;
        count++;
    }
    return (count);
}