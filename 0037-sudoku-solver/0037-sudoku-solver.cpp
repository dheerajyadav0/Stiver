class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;

                            if (solve(board))
                                return true;
                            else
                                board[i][j] = '.'; // backtrack
                        }
                    }
                    return false; // No valid number found
                }
            }
        }
        return true; // Board completely filled
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c) return false;          // Check column
            if (board[row][i] == c) return false;          // Check row
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;                              // Check 3x3 sub-box
        }
        return true;
    }
};
