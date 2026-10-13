class Solution {
public:
using ll= long long;
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<ll>v;
        for(auto u:nums)v.push_back(u*u);
        sort(begin(v),end(v));
        ll sum=0;
        int i=0,j=n-1,cnt=0;
        while(i <= j)
        {
          if(cnt%2==0) sum+=v[j--];
          else sum-=v[i++];
          cnt++;
        }
        
        return sum;
    }
};