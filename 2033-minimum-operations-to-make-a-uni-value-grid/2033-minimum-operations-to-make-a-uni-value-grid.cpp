class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>v;
        for(int i=0; i<grid.size(); i++)
        {
           for(int j=0; j<grid[i].size(); j++) v.push_back(grid[i][j]);
        }
        int n=v.size();
        nth_element(begin(v),begin(v)+n/2, end(v));
        int mid=v[n/2];
        int ans=0;
        for(int i=0; i<v.size(); i++)
        {
          int res=abs(v[i]-mid);
          if(res%x!=0) return -1;
          ans+=res/x;
        }
        return ans;
    }
};