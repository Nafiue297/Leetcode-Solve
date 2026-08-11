class Solution {
public:
    int missingInteger(vector<int>& nums) {
      int n=nums.size();
      int mx=nums[0];
      unordered_map<int,int>mp;
      for(auto u:nums)mp[u]++;
      for( int i=1; i<n; i++)
      {
         if(nums[i-1]+1==nums[i])mx+=nums[i];
         else break;
      }
      if(!mp.count(mx))return mx;

    while(1)
    {
        if(!mp.count(mx))return mx;
        mx++;
    }
     return 0;
    }
};