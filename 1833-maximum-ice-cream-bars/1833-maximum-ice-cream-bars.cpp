class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int cnt=0;
        for(auto u:costs)
        {
         if(coins-u>=0)
         {
            coins-=u;
            cnt++;
         }
        }
        return cnt;
    }
};