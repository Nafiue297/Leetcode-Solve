class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
    int n=nums.size();
    int mx=0;
    int left=0;
    unordered_map<int,int>mp;
    for(int right=0;right<n;right++)
    {
        mp[nums[right]]++;
        while(mp[nums[right]]>k)
        {
            mp[nums[left]]--;
            left++;
        }
     mx=max(mx,right-left+1);
    }
    return mx;
    }
};