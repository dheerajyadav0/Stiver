class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i=0; i<9; ++i) {
            vector<int> row(10,0), col(10,0);
            for (int j=0; j<9; ++j) {
                if (board[i][j] != '.') {
                    if (++row[board[i][j]-'0']==2) return false;
                }
                if (board[j][i] != '.') {
                    if (++col[board[j][i]-'0']==2) return false;
                }
            }
        }
        for (int i=0; i<9; i+=3) {
            for (int j=0; j<9; j+=3) {
                vector<int> box(10,0);
                for (int k=i; k<i+3; ++k) {
                    for (int l=j; l<j+3; ++l) {
                        if (board[k][l] == '.') continue;
                        if (++box[board[k][l]-'0']==2) return false;
                    }
                }
            }
        }
        return true;
    }
};