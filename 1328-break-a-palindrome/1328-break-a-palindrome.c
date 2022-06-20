

char * breakPalindrome(char * palindrome)
{
    int i = -1, len = -1;
    
    while (palindrome[++len]);
    if (len == 1)
        return ("");
    while (++i <= len / 2 && (!(len % 2) || i != len / 2))
        if (palindrome[i] != 'a')
        {
            palindrome[i] = 'a';
            return (palindrome);
        }
    palindrome[len - 1]++;
    return (palindrome);
}