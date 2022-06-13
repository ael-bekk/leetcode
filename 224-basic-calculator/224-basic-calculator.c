#include <stdio.h>

int calcul(char **s)
{
    int sign;
    int a, nb;

    nb = 0;
    sign = 1;
    a = 0;
    if (!**s) return (0);
    while (**s == ' ' || **s == '+') (*s)++;
    if (**s == '-'){sign = -1; (*s)++;}
    while (**s == ' ') (*s)++;
    if (**s == '(')
    {
        (*s)++;
        nb += sign * calcul(s);
    }
    while (**s >= '0' && **s <= '9')
    {
        a = a * 10 + (**s - '0');
        (*s)++;
    }
    nb += a * sign;
    if (**s == ')'){(*s)++; return (nb);}
    return nb + calcul(s);
}

int calculate(char * s)
{
    return calcul(&s);
}