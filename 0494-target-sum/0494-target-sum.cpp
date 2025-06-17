class Solution {
private:
    int countSubsets(int ind, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (ind == 0) {
            if (target == 0 && nums[0] == 0) return 2; 
            if (target == 0 || target == nums[0]) return 1;
            return 0;
        }

        if (dp[ind][target] != -1) return dp[ind][target];

        int notTake = countSubsets(ind - 1, target, nums, dp);
        int take = 0;
        if (nums[ind] <= target)
            take = countSubsets(ind - 1, target - nums[ind], nums, dp);

        return dp[ind][target] = take + notTake;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);

       
        if ((target + total) % 2 != 0 || total < abs(target)) return 0;

        int s1 = (target + total) / 2;

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(s1 + 1, -1));

        return countSubsets(n - 1, s1, nums, dp);
    }
};
