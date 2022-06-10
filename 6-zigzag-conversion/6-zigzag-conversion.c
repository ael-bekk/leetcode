

char * convert(char * s, int numRows){
    int i = 0, len = -1, tmp, j = -1;
    char *str;
    bool ent;

    if (numRows == 1)
        return (s);
    while (s[++len]);
    str = (char *)malloc(sizeof(char) * (len + 1));
    while (++j < numRows)
    {
        tmp = j;
        ent = 1;
        while (tmp < len)
        {
            str[i++] = s[tmp];
            if (j == 0 || j == numRows - 1)
                tmp += (numRows - 1) * 2;
            else if (ent)
                tmp += (numRows - j - 1) * 2;
            else
                tmp += (j * 2);
            ent = !ent;
        }
    }
    str[i] = '\0';
    return (str);
}