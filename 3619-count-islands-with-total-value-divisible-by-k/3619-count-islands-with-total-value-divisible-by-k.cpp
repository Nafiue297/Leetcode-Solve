class Solution {
public:
    int n, m;
    using ll= long long;
    void dfs(int i, int j, vector<vector<int>>& grid, ll& sum) {
        if (i < 0 || j < 0 || i >= n || j >= m ||
            grid[i][j] == 0)
            return;

        sum += grid[i][j];
        grid[i][j] = 0;

        dfs(i - 1, j, grid, sum);
        dfs(i + 1, j, grid, sum);
        dfs(i, j - 1, grid, sum);
        dfs(i, j + 1, grid, sum);
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {
                    ll sum = 0;
                    dfs(i, j, grid, sum);

                    if (sum % k == 0)
                        cnt++;
                }
            }
        }

        return cnt;
    }
};