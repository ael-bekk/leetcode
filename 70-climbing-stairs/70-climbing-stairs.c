#define MIN(a,b) (((a)<(b))?(a):(b))

int tab[46] = {0};

int climbStairs(int n)
{
    if(n <=0)
        return (MIN(n, 0) + 1);
    if(tab[n] != 0)
        return tab[n];
    tab[n] = climbStairs(n-1) + climbStairs(n-2);
    return (tab[n]);
}