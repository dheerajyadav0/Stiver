class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return countPairsWithSumAtMost(nums, upper) - countPairsWithSumAtMost(nums, (long long)lower - 1);
    }

private:
    long long countPairsWithSumAtMost(vector<int>& nums, long long maxSum) {
        int n = nums.size();
        long long count = 0;

        for (int i = 0; i < n; ++i) {
           
            auto it = upper_bound(nums.begin() + i + 1, nums.end(), maxSum - nums[i]);
            count += (it - (nums.begin() + i + 1));
        }

        return count;
    }
};
