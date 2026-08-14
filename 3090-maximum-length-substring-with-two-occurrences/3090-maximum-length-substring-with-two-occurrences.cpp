class Solution {
public:
    int maximumLengthSubstring(string s) {
       int n=s.size();
       unordered_map<char,int>mp;
       int left=0,mx=0;
       for(int right=0; right<n; right++)
       {
         mp[s[right]]++;
         while(mp[s[right]]>2)
         {
            mp[s[left]]--;
            left++;
         }
         mx=max(mx,right-left+1);
       } 
       return mx;
    }
};