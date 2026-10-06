class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        int cnt=0;
        int close=0;
        for(int i=0; i<n; i++)
        {
            if(s[i] == '(')cnt++;
            else
            {
                if(cnt==0) close++;
                else
               cnt--;
            }
        }
        return close+cnt;
    }
};