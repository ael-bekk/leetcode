
int reverse(int x){
    long long int rev;
    int sine;
    long long int nb;

    sine = 1;
    nb = x;
    if (nb < 0)
    {
        sine = -1;
        nb *= -1;
    }
    rev = 0;
    while (nb > 0)
    {
        rev = rev * 10 + nb % 10;
        nb /= 10;
    }
    rev *= sine;
    if (rev < -2147483648 || rev > 2147483647)
          return (0);  
    return ((int)rev);
}