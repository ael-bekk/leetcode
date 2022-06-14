

void reverseString(char* s, int sSize)
{
    int i = -1;

    while (++i < --sSize)
        s[sSize] ^= s[i] ^= s[sSize] ^= s[i];
}