
int equal(char * s1, char * s2)
{
    int i;

    i = -1;
    while (s1[++i] && s1[i] == s2[i]);
    if (s1[i] || s2[i])
        return (0);
    return (1);
}


bool areAlmostEqual(char * s1, char * s2){
    int i;
    int count;
    char a;
    char b;

    if (equal(s1, s2))
        return (1);
    a = -1;
    b = -1;
    i = 0;
    count = 0;
    while (s1[i] && s2[i])
    {
        if (s1[i] == s2[i])
            i++;
        else if (a == -1)
        {
            a = s1[i];
            b = s2[i];
            i++;
        }
        else if (!count && (b == s1[i] && a == s2[i]))
        {
            count++;
            i++;
        }
        else
            return (0);
    }
    return (1 * (count != 0 || a == -1));
}