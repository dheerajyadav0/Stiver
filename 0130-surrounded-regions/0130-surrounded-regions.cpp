class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vis[row][col] = 1;
        int delrow[4] = {1, -1, 0, 0};
        int delcol[4] = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                vis[nrow][ncol] == 0 && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, vis, board);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;  // Edge case for empty board
        int n = board[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        // Process first and last column
        for (int i = 0; i < m; i++) {
            if (vis[i][0] == 0 && board[i][0] == 'O') {
                dfs(i, 0, vis, board);
            }
            if (vis[i][n - 1] == 0 && board[i][n - 1] == 'O') {
                dfs(i, n - 1, vis, board);
            }
        }

        // Process first and last row
        for (int j = 0; j < n; j++) {
            if (vis[0][j] == 0 && board[0][j] == 'O') {
                dfs(0, j, vis, board);
            }
            if (vis[m - 1][j] == 0 && board[m - 1][j] == 'O') {
                dfs(m - 1, j, vis, board);
            }
        }

        // Convert surrounded regions
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 0 && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
