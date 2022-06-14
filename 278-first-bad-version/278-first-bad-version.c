// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n)
{
    unsigned int i = 0, middl;

    while (i < n)
    {
        middl = (i + n) / 2;
        if (isBadVersion(middl))
            n = middl;
        else
            i = middl + 1;
    }
    return (n);
}