

int mySqrt(int x)
{
    int l = 0 , r = x / 2, mid;

    if (!x || !(x - 1))
        return (x);

    while (l <= r)
    {
        mid = (l + r + 1) / 2;
        if (mid < x / mid)
            l = mid + 1;
        else if (mid > x / mid)
            r = mid - 1;
        else
            return (mid);
    }
    return (r);
}