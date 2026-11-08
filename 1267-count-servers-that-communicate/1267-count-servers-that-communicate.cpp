class Solution {
public:
int n,m;

bool dfs(int i, int j, vector<vector<int>>&grid)
{
    for(int col=0; col<m; col++)
    {
        if(col!=j and grid[i][col] == 1) return true;
    }
    for(int row=0; row<n; row++)
    {
        if(row!=i and grid[row][j] == 1) return true;
    }
     return false;
}
    int countServers(vector<vector<int>>& grid) {
         n=grid.size();
         m=grid[0].size();
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 1)
                {
                  if(dfs(i,j, grid))
                    cnt++;
                }
            }
        }
    return cnt;
    }
};