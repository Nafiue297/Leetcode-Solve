class Solution {
public:
    int minMoves(vector<int>& nums) {
       int mn=*min_element(begin(nums),end(nums));
       int n=nums.size();
       int ans=0;
       for(int i=0; i<n; i++) ans+=nums[i]-mn;
       
      return ans; 
    }
};