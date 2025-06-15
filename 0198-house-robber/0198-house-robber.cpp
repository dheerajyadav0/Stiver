class Solution {
    private:
    int robber(int ind, vector<int>& nums, vector<int>& dp) {
        if (ind == 0) return nums[0];
        if (ind == 1) return max(nums[0], nums[1]);
        if (dp[ind] != -1) return dp[ind];

        return dp[ind] = max(nums[ind] + robber(ind - 2, nums, dp), robber(ind - 1, nums, dp));
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        vector<int> dp(n, -1);
        return robber(n - 1, nums, dp);
    }
};
