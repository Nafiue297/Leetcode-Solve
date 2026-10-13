class Solution {
public:
using ll= long long;
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=0; i<n; i++) nums[i]=nums[i]*nums[i];
        sort(begin(nums),end(nums));
        ll sum=0;
        int i=0,j=n-1,cnt=0;
        while(i <= j)
        {
          if(cnt%2==0) sum+=nums[j--];
          else sum-=nums[i++];
          cnt++;
        }
        
        return sum;
    }
};