

int getSum(int a, int b)
{
    unsigned int and;

    while (a)
    {
        and = a & b;
        b = b^a;
        a = and << 1;
    }
    return (b);
}