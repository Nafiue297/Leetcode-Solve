class Solution {
public:
    int minMoves(vector<int>& nums) {
       
        int mx=*max_element(begin(nums),end(nums));
        int ans=0;
        for(int u: nums) ans+=mx-u;
        return ans;
    }
};