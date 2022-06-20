

char * reversePrefix(char * word, char ch)
{
    int i = -1,j = 0;
    char tmp;

    while (word[j] && word[j] != ch)
        j++;
    if (word[j])
        while (++i < j)
        {
            tmp = word[i];
            word[i] = word[j];
            word[j--] = tmp;
        }
    return (word);
}