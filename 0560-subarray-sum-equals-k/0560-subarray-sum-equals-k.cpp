class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>pref(n,0);
        pref[0]=nums[0];
        for(int i=1; i<n; i++) pref[i]=pref[i-1]+nums[i];
        int cnt=0;
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++)
        {
            if(pref[i]==k)cnt++;
            int val=pref[i]-k;
            if(mp.find(val)!=mp.end())
            {
                cnt+=mp[val];
            }
            if(mp.find(pref[i])==mp.end())
            {
                mp[pref[i]]=0;
            }
            mp[pref[i]]++;
        }
    return cnt;
    }
};