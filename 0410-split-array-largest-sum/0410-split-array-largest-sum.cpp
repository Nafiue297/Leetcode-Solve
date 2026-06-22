class Solution {
public:
 bool helper(vector<int>&nums, int k, int mid)
 {
    int sum=0;
    int cnt=1;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]+sum<=mid)
        {
            sum+=nums[i];
        }
        else
        {
          cnt++;
          sum=nums[i];
          if(cnt>k)return false;
        
        }
    }
    return true;
 }
 
    int splitArray(vector<int>& nums, int k) {
        int low=0,high=0;
        for(int i=0;i<nums.size();i++)
        {
            low=max(low,nums[i]);
            high+=nums[i];

        }
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(helper(nums,k,mid))
            {
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }
        return ans;
    }
};