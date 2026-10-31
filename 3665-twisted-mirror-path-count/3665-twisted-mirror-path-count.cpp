class Solution {
public:
    int MOD = 1e9 + 7;
    int n, m;

    int solve(int i, int j, int dr, vector<vector<int>>& grid,
              vector<vector<vector<int>>>& dp)
    {
        if(i == n-1 && j == m-1) return 1;
        if(i >= n || j >= m) return 0;

        if(dp[i][j][dr] != -1) return dp[i][j][dr];

        if(grid[i][j] == 0)
        {
            int total = 0;

            total = (total + solve(i, j+1, 0, grid, dp)) % MOD;
            total = (total + solve(i+1, j, 1, grid, dp)) % MOD;

            return dp[i][j][dr] = total;
        }
        else
        {
            if(dr == 0)
                return dp[i][j][dr] = solve(i+1, j, 1, grid, dp);

            else
                return dp[i][j][dr] = solve(i, j+1, 0, grid, dp);
        }
    }

    int uniquePaths(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(2, -1))
        );

        return solve(0, 0, 0, grid, dp);
    }
};