

int getSum(int a, int b)
{
    unsigned int and = a & b;

    if (!a)
        return (b);
    return (getSum(and << 1, b^a));
}