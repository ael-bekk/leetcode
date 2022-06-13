

int lengthOfLastWord(char * s)
{
    int count = 1, len = strlen(s);

    while (--len >= 0)
        if (s[len] != ' ')
        {
            while (--len >= 0 && s[len] != ' ')
                count++;
            return (count);
        }
    return (0);
}