class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxdiff = -1;
        int minVal = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > minVal) {
                maxdiff = max(maxdiff, nums[i] - minVal);
            } else {
                minVal = nums[i];
            }
        }

        return maxdiff;
    }
};