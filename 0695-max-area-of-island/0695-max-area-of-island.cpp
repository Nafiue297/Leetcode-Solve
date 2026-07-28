class Solution {
public:
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
bool valid(int i,int j,int n,int m)
{
    return(i>=0 and i<n and j>=0 and j<m);
}
void dfs(int i,int j,vector<vector<int>>&grid,vector<vector<bool>>&vis,int &ans,int &cnt,int n,int m)
{
     vis[i][j]=1;
     cnt++;
     ans=max(ans,cnt);
     for(int k=0;k<4;k++)
     {
        int row=i+dx[k];
        int col=j+dy[k];
    if(valid(row,col,n,m) and !vis[row][col] and grid[row][col]==1)
    {
        dfs(row,col,grid,vis,ans,cnt,n,m);
    }
     }
     
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       int ans=0;
       vector<vector<bool>>vis(n,vector<bool>(m,false));
       for(int i=0;i<n;i++)
       {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1 and !vis[i][j])
            {
                int cnt=0;
                dfs(i,j,grid,vis,ans,cnt,n,m);
            }
        }
       } 
       return ans;
    }
};