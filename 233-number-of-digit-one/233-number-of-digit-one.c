#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
int countDigitOne(int n)
{
    int nb;
    long long i;
    long long j;

    nb = 0;
    i = 1;
    while (i <= n)
    {
        j = i * 10;
        nb += (n / j) * i + MIN(MAX((n % j) - i + 1,0),i);
        i *= 10;
    }
    return (nb);
}