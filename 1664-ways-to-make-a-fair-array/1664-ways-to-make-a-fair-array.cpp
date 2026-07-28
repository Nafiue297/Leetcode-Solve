class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
      int rightodd=0,righteven=0;
      int leftodd=0,lefteven=0;
      int res=0;
      int n=nums.size();
      for(int i=0;i<n;i++)
      {
       if(i&1)rightodd+=nums[i];
       else leftodd+=nums[i];
      }  
      for(int i=0;i<n;i++)
      {
        if(i&1)rightodd-=nums[i];
        else righteven-=nums[i];
        if(leftodd+righteven==lefteven+rightodd)res++;
        if(i&1)leftodd+=nums[i];
        else lefteven+=nums[i];
      }
      return res;
    }
};