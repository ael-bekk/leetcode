#define MIN(X,Y) ((X < Y) ? X : Y)
void reverseString(char* s, int i, int j)
{
    while (++i < --j)
    {
        s[j] ^= s[i];
        s[i] ^= s[j];
        s[j] ^= s[i];
    }
}

char * reverseStr(char * s, int k)
{
    int i = 0, len = -1;

    while (s[++len]);
        
    while (i < len)
    {
        reverseString(s, i - 1, MIN(i + k, len));
        i += k * 2;
    }
    return (s);
}