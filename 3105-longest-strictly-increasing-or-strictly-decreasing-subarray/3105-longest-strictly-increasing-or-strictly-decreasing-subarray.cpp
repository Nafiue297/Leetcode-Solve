class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
       int n=nums.size();
       int inc=1,dec=1,mx=1;
       for(int i=0; i<n-1; i++)
       {
         if(nums[i+1]>nums[i])
         {
            inc++;
            dec=1;
         }
         else if(nums[i+1]<nums[i])
         {
            dec++;
            inc=1;
         }else
         {
            inc=1;
            dec=1;
         }
         mx=max(mx,max(inc,dec));
       }
    return mx;
    }
};