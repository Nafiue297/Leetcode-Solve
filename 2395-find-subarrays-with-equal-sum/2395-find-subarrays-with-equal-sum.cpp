class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0; i<n-1; i++)
        {
            if(mp[nums[i]+nums[i+1]]) return true;
            mp[nums[i]+nums[i+1]]++;
        }
        return false;
    }
};