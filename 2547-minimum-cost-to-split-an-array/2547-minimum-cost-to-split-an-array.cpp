class Solution {
public:
 int split[1001][1001];
 int dp[1001];
 int solve(vector<int>& nums, int k, int ind)
 {
    if(ind>=nums.size()) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int score=INT_MAX;
    for(int i=ind; i<nums.size(); i++)
    {
        int curr=k+split[ind][i]+solve(nums, k, i+1);
        score=min(score,curr);
    }
    return dp[ind]=score;
 }
    int minCost(vector<int>& nums, int k) {
       int n=nums.size();
       memset(dp,-1,sizeof(dp));
       for(int i=0; i<n; i++)
       {
         unordered_map<int,int>mp;
         int trim=0;
         for(int j=i; j<n; j++)
         {
            mp[nums[j]]++;
            if(mp[nums[j]]==2) trim+=2;
            else if(mp[nums[j]]>2) trim++;
            split[i][j]=trim;
         }
       }
    return solve(nums, k, 0);


    }
};