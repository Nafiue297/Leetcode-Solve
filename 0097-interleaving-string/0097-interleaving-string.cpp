class Solution {
public:
int dfs(int i,int j,string&s1,string&s2,string&s3,vector<vector<int>>&dp)
{
    if(i==s1.size() and j==s2.size())return true;
    if(dp[i][j]!=-1)return dp[i][j];
    bool ans=false;
    int k=i+j;
    if(i<s1.size())
    {
        if(s1[i]==s3[k])
        {
           ans|= dfs(i+1,j,s1,s2,s3,dp);
        }
    }
    if(j<s2.size())
    {
        if(s2[j]==s3[k])
        {
          ans|=  dfs(i,j+1,s1,s2,s3,dp);
        }
    }
    return dp[i][j]=ans;
}
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        if(n+m!=s3.size())return false;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return dfs(0,0,s1,s2,s3,dp);
    }
};