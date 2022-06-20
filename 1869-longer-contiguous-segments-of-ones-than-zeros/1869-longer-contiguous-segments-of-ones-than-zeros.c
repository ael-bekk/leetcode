

bool checkZeroOnes(char * s)
{
    int i = 0, count1, count0, max0 = 0, max1 = 0;
    
    while (s[i])
    {
        count1 = 0;
        count0 = 0;
        while (s[i] && s[i] == '1')
        {
            i++;
            count1++;
        }
            
        while (s[i] && s[i] == '0')
        {
            i++;
            count0++;
        }
        if (max1 < count1)
            max1 = count1;
        if (max0 < count0)
            max0 = count0;
    }
    return (max1 > max0);
}