uint32_t reverseBits(uint32_t n)
{
    uint32_t nb = 0, i = 32;

    while (i--)
    {
        nb <<= 1;
        nb += n % 2;
        n >>= 1;
    }
    return (nb);
}