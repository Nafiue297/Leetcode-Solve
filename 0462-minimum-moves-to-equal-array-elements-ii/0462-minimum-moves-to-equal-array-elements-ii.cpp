class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int med1=-1;
        int med2=-1;
    sort(begin(nums),end(nums));
        if(n%2 ==0)
        {
            med2=nums[n/2];
            med1=nums[n/2-1];
        } else med2=nums[n/2];
        if(med1==-1)
        {
            for(int i=0; i<n; i++)
            {
                ans+=abs(nums[i]-med2);
            }
            return ans;
        }else
        {
           int m=0,M=0;
            for(int i=0; i<n; i++)
            {
               m+=abs(nums[i]-med1);
               M+=abs(nums[i]-med2);
               ans=min(m,M);
            }
            return ans;
        }
       return -1; 
    }
};