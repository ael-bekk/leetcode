

int search(int* dist, int s, double hour, int div)
{
    int j = -1, min;
    double minspeed = 0;
    
    while (++j < s)
    {
        minspeed += (double)dist[j] / div;
        if (j + 1 < s)
        {
            min = minspeed;
            minspeed -= min;
            if (minspeed != 0)
                minspeed = min + 1;
            else
                minspeed = min;
        }
    }
    if (minspeed <= hour)
        return (div);
    return (-1);
}

int minSpeedOnTime(int* dist, int s, double hour)
{
    int  r = 0, l = 10000000, j = -1, min;
    double minspeed;
    
    while (r <= l)
    {
        if (search(dist, s, hour, (r + l + 1) / 2) != -1)
            l = (r + l + 1) / 2 - 1;
        else
            r = (r + l + 1) / 2 + 1;
    }
    return (search(dist, s, hour, (r + l + 1) / 2));
}