class Solution {
public:
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
bool valid(int i,int j,int n,int m)
{
    return (i>=0 and j>=0 and i<n and j<m);
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      int n=grid.size();
      int m=grid[0].size();
      queue<pair<int,int>>q;
      vector<vector<bool>>vis(n,vector<bool>(m,false));
      int ans=0;
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1 and !vis[i][j])
            {
                q.push({i,j});
                vis[i][j]=true;
            }
           int cnt=0;
           while(!q.empty())
           {
            auto [x,y]=q.front();
            q.pop();
            cnt++;
         for(int k=0;k<4;k++)
         {
            int row=x+dx[k];
            int col=y+dy[k];
          if(valid(row,col,n,m) and !vis[row][col] and grid[row][col]==1)
          {
            q.push({row,col});
            vis[row][col]=true;
          }
         }
         ans=max(ans,cnt);
           }
        }
      }
      return ans;  
    }
};