class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int prev = ind - 1; prev >= -1; prev--) {
                int notTake = dp[ind + 1][prev + 1];  // don't take nums[ind]
                int take = 0;
                if (prev == -1 || nums[ind] > nums[prev]) {
                    take = 1 + dp[ind + 1][ind + 1];  // take nums[ind]
                }
                dp[ind][prev + 1] = max(notTake, take);
            }
        }
        return dp[0][-1+1];  
    }
};
