class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int mx=0;
        bool zero=true;
        for(auto u:nums)
        {
            mx^=u;
            if(mx!=0)zero=false;

        }
        if(mx!=0)return n;
        if(zero)return 0;
        return n-1;
        
        
    }
};