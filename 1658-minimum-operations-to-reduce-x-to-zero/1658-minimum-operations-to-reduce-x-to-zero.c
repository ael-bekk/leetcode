#define MIN(X, Y) ((X > Y) ? Y : X)

int minOperations(int* nums, int n, int x){
   int l = 0, r = 0, i = -1, max = -1;

    for (int j = 0; j < n; j++) x -= nums[j];
    x *= -1;
    while (++i < n)
    {
        if (x - nums[i] >= 0)
            x -= nums[i],
            r++;
        else if (l < r)
            x += nums[l++],
            i--;
        else
            l = r = i + 1;
        if (!x && (max == -1 || max < r - l))
            max = r - l;
    }
    return ((max > -1) ? n - max : -1);
}