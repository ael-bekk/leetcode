
int And(int left, int right, int i)
{
    if (left == right)
        return (left << i);
    return (And(left >> 1, right >> 1, i + 1));
}

int rangeBitwiseAnd(int left, int right)
{
    return (And(left, right, 0));
}