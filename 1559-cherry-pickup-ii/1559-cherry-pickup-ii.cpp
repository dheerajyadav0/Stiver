class Solution {
public:
    int dp[71][71][71]; 

    int f(int i, int j1, int j2, vector<vector<int>>& grid, int n, int m) {
        
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -1e9;

        
        if (i == n - 1) {
            if (j1 == j2) return grid[i][j1];
            return grid[i][j1] + grid[i][j2];
        }


        if (dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int maxi = INT_MIN;
        // 9 combinations
        for (int dj1 = -1; dj1 <= 1; dj1++) {
            for (int dj2 = -1; dj2 <= 1; dj2++) {
                int value;
                if (j1 == j2)
                    value = grid[i][j1];
                else
                    value = grid[i][j1] + grid[i][j2];

                value += f(i + 1, j1 + dj1, j2 + dj2, grid, n, m);
                maxi = max(maxi, value);
            }
        }

        return dp[i][j1][j2] = maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return f(0, 0, m - 1, grid, n, m); 
    }
};
