class Solution {
    vector<int> dp;

    int f(int i, int n) {
        if (i == n) {
            return 1;
        }

        if (i > n) {
            return 0;
        }

        if (dp[i] != -1) return dp[i];

        return dp[i] = f(i + 1, n) + f(i + 2, n);
    }

public:
    int climbStairs(int n) {
        dp = vector<int>(n + 1, -1);
        return f(0, n);
    }
};
