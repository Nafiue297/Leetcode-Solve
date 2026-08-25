class Solution {
public:
bool solve(int i,vector<int>& nums, int s, vector<vector<int>>& dp)
{
    if(s==0)return true;
    if(i==nums.size())return false;
    if(dp[i][s]!=-1) return dp[i][s];
    bool nottake=solve(i+1, nums, s, dp);
    bool take=false;
    if(nums[i]<=s)
    {
        take=solve(i+1, nums, s-nums[i], dp);
    }
    return dp[i][s]=take|nottake;
}
    bool canPartition(vector<int>& nums) {
        int s=accumulate(nums.begin(),nums.end(),0);
        if(s%2==1)return false;
        int n=nums.size();
        s/=2;
        vector<vector<int>>dp(n,vector<int>(s+1,-1));
        
        return solve(0, nums, s, dp);
    }
};