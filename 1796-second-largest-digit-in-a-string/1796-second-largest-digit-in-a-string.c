

int secondHighest(char * s)
{
    int i = -1, l1 = -1, l2 = -1;

    while (s[++i])
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            if (s[i] - '0' > l1)
            {
                l2 = l1;
                l1 = s[i] - '0';
            }
            else 
                if (l1 != s[i] - '0')
                    l2 = (l2 < s[i] - '0')? s[i] - '0': l2; 
        }
    }
    return l2;
}