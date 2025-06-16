class Solution {
private:
    int solve(int ind, int buy, int limit, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        if (ind == prices.size()) return 0;
        if (limit == 0) return 0;

        if (dp[ind][buy][limit] != -1) return dp[ind][buy][limit];

        int profit = 0;
        if (buy) {
            int buyKaro = -prices[ind] + solve(ind + 1, 0, limit, prices, dp);
            int skipKaro = solve(ind + 1, 1, limit, prices, dp);
            profit = max(buyKaro, skipKaro);
        } else {
            int sellKaro = prices[ind] + solve(ind + 1, 1, limit - 1, prices, dp);
            int skipKaro = solve(ind + 1, 0, limit, prices, dp);
            profit = max(sellKaro, skipKaro);
        }

        return dp[ind][buy][limit] = profit;
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // dp[n][2][k+1]
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return solve(0, 1, k, prices, dp);
    }
};
