

int hammingDistance(int x, int y)
{
    if (!x && !y)
        return (0);
    return (((x % 2) != (y % 2)) + hammingDistance(x / 2, y / 2));
}