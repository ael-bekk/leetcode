
int tribonacci(int n)
{

    unsigned int i = 0, l1 = 0, l2 = 1, l3 = 1;
    
    while (++i <= n)
    {
        l2 += l1;
        l1 = l2 - l1;
        l3 += l2;
        l2 = l3 - l2;
    }
    return (l1);
}