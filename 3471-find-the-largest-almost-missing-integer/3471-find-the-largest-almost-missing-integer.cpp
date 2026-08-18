class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> mp;
        unordered_map<int,int> window;

        int left = 0;

        for(int right = 0; right < n; right++)
        {
            window[nums[right]]++;

            while(right - left + 1 > k)
            {
                window[nums[left]]--;

                if(window[nums[left]] == 0)
                    window.erase(nums[left]);

                left++;
            }

            if(right - left + 1 == k)
            {
           
                for(auto u : window)
                {
                    mp[u.first]++;
                }
            }
        }

        int ans = -1;

        for(auto u : mp)
        {
            if(u.second == 1)
                ans = max(ans, u.first);
        }

        return ans;
    }
};