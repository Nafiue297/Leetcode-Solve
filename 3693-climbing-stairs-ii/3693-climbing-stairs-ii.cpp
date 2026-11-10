class Solution {
public:
int solve(int n, int i, vector<int>&dp, vector<int>&costs)
{
    if(i==n) return 0;
    if(dp[i]!=-1) return dp[i];
    int step1=INT_MAX, step2=INT_MAX, step3=INT_MAX;
    if(i+1<=n) step1=costs[i]+1+solve(n,i+1,dp,costs);
    if(i+2<=n) step2=costs[i+1]+4+solve(n,i+2,dp,costs);
    if(i+3<=n) step3=costs[i+2]+9+solve(n,i+3,dp,costs);
    return dp[i]=min({step1,step2,step3});
}
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1,INT_MAX);
        dp[n]=0;
        for(int i=n-1; i>=0; i--)
        {
           if(i+1<=n) dp[i]=min(dp[i], costs[i]+1+dp[i+1]);
           if(i+2<=n) dp[i]=min(dp[i], costs[i+1]+4+dp[i+2]);
           if(i+3<=n) dp[i]=min(dp[i], costs[i+2]+9+dp[i+3]);
        }
        return dp[0];
    }
};