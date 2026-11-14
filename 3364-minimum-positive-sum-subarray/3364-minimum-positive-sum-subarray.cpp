class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int mn = INT_MAX;

        for(int i = 0; i < n; i++)
        {
            int sum = 0;

            for(int j = i; j < min(n, i + r); j++)
            {
                sum += nums[j];

                int len = j - i + 1;

                if(len >= l && sum > 0)
                    mn = min(mn, sum);
            }
        }

        return mn == INT_MAX ? -1 : mn;
    }
};