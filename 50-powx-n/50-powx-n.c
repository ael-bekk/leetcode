

double myPow(double x, int n){
    if (!n)
        return (1);
    if (n > 0 && n % 2)
        return (x * myPow(x, n - 1));
    if (n % 2)
        return ((1 / x) * myPow(x, n + 1));
    return (myPow(x, n / 2) * myPow(x, n / 2));
}