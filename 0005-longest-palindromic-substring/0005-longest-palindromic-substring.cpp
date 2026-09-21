class Solution {
public:
bool ispalin(string &s, int i, int j, vector<vector<int>>&dp)
{
    if(i>=j) return true;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i] == s[j]) return dp[i][j]=ispalin(s, i+1, j-1, dp);
    return false;
  
}

    string longestPalindrome(string s) {
        int n=s.size();
        int mx=INT_MIN;
        string temp="";
        vector<vector<int>>dp(n, vector<int>(n,-1));
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                if(ispalin(s, i, j, dp))
                {
                 if(j-i+1 > mx)
                 {
                    mx=j-i+1;
                    temp=s.substr(i, j-i+1);
                 }
                }
            }
        }
        return temp;
    }
};