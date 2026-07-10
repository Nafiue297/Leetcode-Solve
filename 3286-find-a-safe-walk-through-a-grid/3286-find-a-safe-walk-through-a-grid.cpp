class Solution {
public:
bool valid(int i,int j,int n, int m)
{
    return (i>=0 and j>=0 and i<n and j<m);
}
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>res(n,vector<int>(m,INT_MAX));
        deque<pair<int,int>>dq;
        res[0][0]=grid[0][0];
        dq.push_front({0,0});
        int dx[4]={0,1,0,-1};
        int dy[4]={-1,0,1,0};
        while(!dq.empty())
        {
            auto[i,j]=dq.front();
            dq.pop_front();
        for(int k=0;k<4;k++)
        {
            int nr=i+dx[k];
            int nc=j+dy[k];
        if(!valid(nr,nc,n,m))continue;
        if(res[nr][nc]>grid[nr][nc]+res[i][j])
        {

        
            res[nr][nc]=grid[nr][nc]+res[i][j];
        if(grid[nr][nc]==0)dq.push_front({nr,nc});
        else dq.push_back({nr,nc});
        }
        }
        }
        return res[n-1][m-1]<health;
    }
};