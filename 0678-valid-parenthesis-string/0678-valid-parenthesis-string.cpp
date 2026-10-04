class Solution {
public:
int dp[102][102];
bool solve(int i, int open, string& s)
{
    if(i==s.size()) return open==0;
    if(dp[i][open]!=-1) return dp[i][open];
    bool valid=false;
    if(s[i]=='*')
    {
        valid|=solve(i+1, open+1, s);
        valid|=solve(i+1, open, s);
        if(open>0) valid|=solve(i+1, open-1, s);

    }
    else if(s[i]=='(') valid|=solve(i+1, open+1, s);
    else
    {
        if(open >0) valid|=solve(i+1, open-1, s);
    }
    return dp[i][open]=valid;
}
    bool checkValidString(string s) {
       memset(dp,-1,sizeof(dp));
       return solve(0, 0, s); 
    }
};