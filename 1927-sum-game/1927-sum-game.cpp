class Solution {
public:
    bool sumGame(string nums) {
     int n=nums.size();
     int lsum=0,rsum=0;
     int lq=0,rq=0;
     for(int i=0; i<n; i++)
     {
        if(nums[i]=='?')
        {
            if(i<n/2)
            {
                lq++;
            }else rq++;
        }else
        {
            if(i<n/2)lsum+=nums[i]-'0';
            else rsum+=nums[i]-'0';
        }
     }
     if((lq+rq)%2==1)return true;
     int left=2*lsum+9*lq;
     int right=2*rsum+9*rq;
     return left!=right;   
    }
};