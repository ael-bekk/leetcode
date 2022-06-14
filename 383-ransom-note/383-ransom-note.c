

bool canConstruct(char * ransomNote, char * magazine)
{
    int *alp = (int *)malloc(sizeof(int) * 26);
    int i = -1, j = -1;

    memset(alp, 0, sizeof(int) * 26);
    while (magazine[++j])
        alp[magazine[j] - 'a']++;
    
    while (ransomNote[++i])
        alp[ransomNote[i] - 'a']--;

    i = -1;
    while (++i < 26 && alp[i] >= 0);
    return ((i == 26));
}