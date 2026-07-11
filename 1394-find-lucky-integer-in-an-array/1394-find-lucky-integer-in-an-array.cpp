class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>cnt;
        for(int i=0;i<n;i++)
        {
            cnt[arr[i]]++;
        }
        int ans=-1;
        for(auto u:arr)
        {
            if(cnt[u]==u)
            {
                if(u>ans)ans=u;
            }
        }
        return ans;
    }
};