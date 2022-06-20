class Solution {
public:
    long long maximumSubsequenceCount(string text, string patt) {
        long long arr[2] = {0};
    
        int i = -1;
        while (++i < text.length())
        {
            if (text[i] == patt[0])
                arr[0]++;
            if (text[i] == patt[1])
                arr[1]++;
        }
        
        long long sum = 0, l = 0;

        if (arr[0] <= arr[1])
            sum += arr[1];
        else if (++l)
            sum += arr[0];
        
        i = -1;
        while (++i < text.length())
        {
            if (text[i] == patt[1] && arr[1])
                arr[1]--;
            if (text[i] == patt[0])
                sum += arr[1];
        }
        return (sum);
    }
};