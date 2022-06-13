#define max(X, Y) ((X > Y)? X: Y) 
#define min(X, Y) ((X < Y)? X: Y) 
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long max, min, m = INT_MIN;
        max = min = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (!nums[i])
                max = min = 1;
            else
            {
                long long t = max;
                max = max(max(t * nums[i], nums[i]), min * nums[i]);
                min = min(min(min * nums[i], nums[i]), t * nums[i]);
                m = max(max, m);
            }
             m = max(nums[i], m);
        }
        return (m);
    }
};