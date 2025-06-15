class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        //  initial dp at bottom
        vector<int> prev(triangle[n - 1]);

        //  second-last row to top
        for (int i = n - 2; i >= 0; i--) {
            vector<int> curr(i + 1);
            for (int j = 0; j <= i; j++) {
                int down = triangle[i][j] + prev[j];
                int diagonal = triangle[i][j] + prev[j + 1];
                curr[j] = min(down, diagonal);
            }
            prev = curr;  // Move up
        }
        return prev[0];
    }
};
