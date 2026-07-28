class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      unordered_set<int>st;
      if(nums.size()==0)return 0;
      int cnt=1;
      int ans=1;
      for(auto u:nums)st.insert(u);
      for(auto u:st)
      {
        if(st.find(u-1)==st.end())
        {
           int x=u;
           cnt=1;
           while(st.find(x+1)!=st.end())
           {
             x++;
             cnt++;
           }
           ans=max(ans,cnt);
        }
      } 
      return ans; 
    }
};