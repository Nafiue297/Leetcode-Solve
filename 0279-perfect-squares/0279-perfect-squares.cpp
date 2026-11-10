class Solution {
public:
int solve(int i, int n, vector<int>&nums,vector<vector<int>>&dp)
{
   if(i==0)
   {
     if(n%nums[i]==0) return n/nums[i];
     else return 1e9; 
   }
   if(dp[i][n]!=-1) return dp[i][n];
   int nottake=solve(i-1,n, nums, dp);
   int take=INT_MAX;
   if(nums[i]<=n) take=1+solve(i,n-nums[i],nums,dp);
   return dp[i][n]=min(take,nottake);
}
    int numSquares(int n) {
        vector<int>nums;
        for(int i=1; i*i<=n; i++) nums.push_back(i*i);
        int N=nums.size();
        vector<vector<int>>dp(N,vector<int>(n+1,-1));
        return solve(N-1,n,nums,dp);
        

    }
};