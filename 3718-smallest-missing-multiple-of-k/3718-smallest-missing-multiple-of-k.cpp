class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto u:nums)mp[u]++;
        int cnt=1;
        while(mp.count(k*cnt))cnt++;
        return k*cnt;
       
    }
};