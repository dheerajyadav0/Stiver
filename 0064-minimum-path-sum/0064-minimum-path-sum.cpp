class Solution {
private:
    int path(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (i == 0 && j == 0) return grid[0][0];
        if (i < 0 || j < 0) return 1e9;  // to avoid taking invalid paths

        if (dp[i][j] != -1) return dp[i][j];

        int up = grid[i][j] + path(i - 1, j, grid, dp);
        int left = grid[i][j] + path(i, j - 1, grid, dp);

        return dp[i][j] = min(up, left);
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return path(m - 1, n - 1, grid, dp);
    }
};
