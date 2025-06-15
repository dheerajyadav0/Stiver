class Solution {
private:
    int robLinear(vector<int>& nums, int start, int end) {
        int prev2 = 0;  
        int prev1 = 0; 

        for (int i = start; i <= end; ++i) {
            int curr = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // Case 1
        int case1 = robLinear(nums, 0, n - 2);

        // Case 2
        int case2 = robLinear(nums, 1, n - 1);

        return max(case1, case2);
    }
};
