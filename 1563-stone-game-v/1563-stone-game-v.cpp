class Solution {
public:
int solve(int l, int r, vector<vector<int>>&dp, vector<int>&pref)
{
    if(l>=r)return 0;
    if(dp[l][r]!=-1)return dp[l][r];
    int score=0;
    for(int mid=l; mid<=r-1; mid++)
    {
        int left=pref[mid]-(l-1>=0?pref[l-1]:0);
        int right=pref[r]-pref[mid];
      if(left<right) score=max(score,left+solve(l,mid,dp,pref));
 else if(left>right) score=max(score,right+solve(mid+1,r,dp,pref));
 else{
    int lscore=max(score,left+solve(l,mid,dp,pref));
    int rscore=max(score,right+solve(mid+1,r,dp,pref));
    score=max(lscore,rscore);
   }   
  
    }
 return dp[l][r]=score;
}
    int stoneGameV(vector<int>& stoneValue) {
     int n=stoneValue.size();
     vector<int>pref(n,0);
     pref[0]=stoneValue[0];
     for(int i=1; i<n; i++)pref[i]=pref[i-1]+stoneValue[i];
     vector<vector<int>>dp(n,vector<int>(n,-1));
     return solve(0,n-1,dp,pref);
    }
};