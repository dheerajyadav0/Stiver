class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> row(n, 1);  // Fix: row should have 'n' elements
        vector<int> col(m, 1);  // Fix: col should have 'm' elements

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 0;
                    col[j] = 0; // Fix: Should update col[j] instead of col[i]
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (row[i] == 0 || col[j] == 0) { 
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
