class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        int i = 0;
        int maxLen = 0;
        int n = nums.size();

        for (int j = 0; j < n; j++) {
            while (nums[j] - nums[i] > 1) {
                i++;
            }
            if (nums[j] - nums[i] == 1) {
                maxLen = max(maxLen, j - i + 1);
            }
        }

        return maxLen;
    }
};
