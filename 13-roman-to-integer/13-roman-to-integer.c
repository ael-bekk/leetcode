int ft_find(char c)
{
    char rom[8] = "IVXLCDM";
    int nbrs[7] = {1, 5, 10, 50, 100, 500, 1000};
    int i;

    i = 0;
    while (rom[i] && rom[i] != c)
        i++;
    return (nbrs[i]);
}

int romanToInt(char * s){
    int i;
    int nb;
    char l;
    int occu;

    i = 0;
    nb = 0;
    while (s[i])
    {
        occu = 1;
        l = s[i];
        i++;
        while (s[i] && l == s[i])
        {
            occu++;
            i++;
        }
        if (!s[i])
        {
            nb += ft_find(l) * occu;
            return (nb);
        }
        else if (ft_find(l) > ft_find(s[i]))
            nb += ft_find(l) * occu;
        else
        {
            nb += ft_find(s[i]) - ft_find(l) * occu ;
            i++;
        }
    }
    return (nb);
}