class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        unordered_map<char,int>mp;
        int n=s.size();
        int left=0, mn=INT_MAX;
        string ans="";
        for(int right=0; right<n; right++)
        {
            mp[s[right]]++;
            while(mp['1']>=k)
            {
                if(right-left+1 < mn){
                mn=right-left+1;
                ans=s.substr(left,right-left+1);
                }
            else if(right-left+1 == mn)
            {
                ans=min(ans,s.substr(left,right-left+1));
            }
               
                mp[s[left]]--;
                left++;

            }

        }
       return mn==INT_MAX?"":ans;
      
    }
};