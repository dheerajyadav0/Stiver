class Solution {
private:
    bool tryAllSubsets(vector<int>& nums, int index, int currentSum, int target, vector<vector<int>>& dp) {
        if (currentSum == target) return true;
        if (index >= nums.size() || currentSum > target) return false;

        if (dp[index][currentSum] != -1) return dp[index][currentSum];

        bool take = tryAllSubsets(nums, index + 1, currentSum + nums[index], target, dp);
        bool notTake = tryAllSubsets(nums, index + 1, currentSum, target, dp);

        return dp[index][currentSum] = take || notTake;
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), total = 0;
        for (int num : nums) total += num;

        if (total % 2 != 0) return false;

        int target = total / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return tryAllSubsets(nums, 0, 0, target, dp);
    }
};
