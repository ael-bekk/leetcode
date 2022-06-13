

int hammingWeight(uint32_t n)
{
    if (!n)
        return (0);
    return (n % 2 + hammingWeight(n>>1));
}