int ft_nbrlen(int nb)
{
    int i;

    i = 0;
    while (nb > 0)
    {
        nb /= 10;
        i++;
    }
    return (i);
}

bool isPalindrome(int x){
    int head;
    int tail;
    int i;

    if (x < 0)
        return (0);
    i = ft_nbrlen(x);
    head = 1;
    tail = 10;
    while (--i > 0)
        head *= 10;
    while (head >= tail)
    {
        if ((x / head) % 10 != (x % tail) * 10 / tail)
            return (false);
        head /= 10;
        tail *= 10;
    }
    return (true);
}