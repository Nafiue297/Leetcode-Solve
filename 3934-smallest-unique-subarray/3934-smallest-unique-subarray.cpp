class Solution {
public:
typedef long long ll;
const int MOD=1e9+7;
ll findpow(int a,int b)
{
    if(b<=0) return 1;
    ll res=findpow(a,b/2);
    res=(res*res)%MOD;
    if(b%2==1)
    {
        res=(a*res)%MOD;
    }
    return res; 
}
bool check(vector<int>&nums,int mid,int base)
{     
      int n=nums.size();
      int left=0;
      ll hash=0;
      unordered_map<ll,int>mp;
      for(int right=0; right<n; right++)
      {
         hash=(hash*base+nums[right])%MOD;
         if(right-left+1==mid)
         {
            mp[hash]++;
            hash=(hash-(nums[left]*findpow(base,mid-1)%MOD)+MOD)%MOD;
            left++;
         }
      }
      for(auto u:mp)
      {
        if(u.second==1) return true;
      }
      return false;
}
    int smallestUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int base=*max_element(begin(nums),end(nums))+1;
        int l=1,r=n,res=n;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(check(nums,mid,base))
            {
                res=mid;
                r=mid-1;
            }else l=mid+1;
        }
        return res;
    }
};