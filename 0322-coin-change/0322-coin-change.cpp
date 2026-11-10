class Solution {
public:
    int solve(int i, int amount, vector<int>& coins, vector<vector<int>>&dp)
    {
    if(i==0) return amount%coins[i]==0?amount/coins[i]:1e9;
    if(dp[i][amount]!=-1) return dp[i][amount];
    int nottake=solve(i-1,amount,coins,dp);
    int take=INT_MAX; 
    if(amount>=coins[i]) {
        take=1+solve(i-1,amount-coins[i],coins,dp);
        take=min(take,1+solve(i,amount-coins[i],coins,dp));
    }
    return dp[i][amount]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
       int n=coins.size();
       vector<vector<int>>dp(n,vector<int>(amount+1,0));
for(int i=0; i<=amount; i++) 
{
    if(i%coins[0]==0) dp[0][i]=i/coins[0];
    else dp[0][i]=1e9;
}
   for(int i=1; i<n; i++)
   {
     for(int j=0; j<=amount; j++)
     {
    int nottake=dp[i-1][j];
    int take=INT_MAX; 
    if(j>=coins[i]) 
        take=1+dp[i][j-coins[i]];
        
    
     dp[i][j]=min(take,nottake);
     }
   }

       int ans= dp[n-1][amount]; 
       return ans>=1e9?-1:ans;
    }
};