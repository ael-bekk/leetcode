

bool judgeSquareSum(int c)
{
    int l = 0 , r = c / 2, mid;
    unsigned int start = 1;
    
    if (!c || !(c - 1))
        return (1);

    while (l <= r)
    {
        mid = (l + r + 1) / 2;
        if (mid == c / mid && !(c % mid))
            return (1);
        else if (mid < c / mid)
            l = mid + 1;
        else if (mid > c / mid)
            r = mid - 1;
        else
            break;
    }
    while (start <= r)
        if (start * start + r * r > c)
            r--;
        else if (start * start + r * r < c)
            start++;
        else
            return (1);
    return (0);
}