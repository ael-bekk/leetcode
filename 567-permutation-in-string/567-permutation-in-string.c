

bool checkInclusion(char * s1, char * s2)
{
    int arr1[26] = {0}, arr2[26] = {0};
    int i;
    char *start = s2;
    
    while (*(s1 + 1) && *s2)
    {
        arr1[*(s1++) - 'a']++;
        arr2[*(s2++) - 'a']++;
    }
    arr1[*(s1++) - 'a']++;
    if (!*s1)
    {
        while (*s2)
        { 
            i = -1;
            arr2[*s2 - 'a']++;
            while (++i < 26 && arr2[i] == arr1[i]);
            if (i == 26)
                return (1);
            arr2[*(start++) - 'a']--;
            s2++;
        }
    }
    return 0;
}