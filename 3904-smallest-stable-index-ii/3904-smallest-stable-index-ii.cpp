class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> prev(n);
        vector<int> next(n);

        // Prefix maximum
        prev[0] = nums[0];

        for(int i = 1; i < n; i++)
        {
            prev[i] = max(prev[i-1], nums[i]);
        }

        // Suffix minimum
        next[n-1] = nums[n-1];

        for(int i = n-2; i >= 0; i--)
        {
            next[i] = min(next[i+1], nums[i]);
        }

        // Find smallest stable index
        for(int i = 0; i < n; i++)
        {
            if(prev[i] - next[i] <= k)
                return i;
        }

        return -1;
    }
};