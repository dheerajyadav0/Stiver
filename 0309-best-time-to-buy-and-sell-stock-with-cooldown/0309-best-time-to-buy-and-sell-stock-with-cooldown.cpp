class Solution {
private:
    int solve(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if (ind >= prices.size()) return 0;

        if (dp[ind][buy] != -1) return dp[ind][buy];

        int profit = 0;
        if (buy) {
            int buyKaro = -prices[ind] + solve(ind + 1, 0, prices, dp);
            int skipKaro = 0 + solve(ind + 1, 1, prices, dp);
            profit = max(buyKaro, skipKaro);
        } else {
            int sellKaro = prices[ind] + solve(ind + 2, 1, prices, dp);  
            int skipKaro = 0 + solve(ind + 1, 0, prices, dp);
            profit = max(sellKaro, skipKaro);
        }

        return dp[ind][buy] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, -1)); 
        return solve(0, 1, prices, dp);
    }
};
