

bool isPerfectSquare(int num)
{
    int l = 0 , r = num / 2, mid;

    if (!(num - 1))
        return (1);

    while (l <= r)
    {
        mid = (l + r + 1) / 2;
        if (mid == num / mid && !(num % mid))
            return (1);
        else if (mid < num / mid)
            l = mid + 1;
        else if (mid > num / mid)
            r = mid - 1;
        else
            break;
    }
    return (0);
}