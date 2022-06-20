int tab[31];

int fib(int n)
{
    if (n < 2)
        return (n);
    if (tab[n])
        return (tab[n]);
    tab[n] = fib(n - 1) + fib(n - 2);
    return (tab[n]);
}