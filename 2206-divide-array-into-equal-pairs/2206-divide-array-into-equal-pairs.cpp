class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int arr[501] = {0};
    
        int i = -1;
        while (++i < nums.size())
            arr[nums[i]]++;
        i = 0;
        while (++i < 501)
            if (arr[i] % 2)
                return (false);
        return (true);
    }
};