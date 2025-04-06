class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> allSubsets(n);  

        for (int i = 0; i < n; i++) {
            vector<int> maxSubset;
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && allSubsets[j].size() > maxSubset.size()) {
                    maxSubset = allSubsets[j];
                }
            }
            allSubsets[i] = maxSubset;
            allSubsets[i].push_back(nums[i]);
        }


        vector<int> result;
        for (auto& subset : allSubsets) {
            if (subset.size() > result.size()) {
                result = subset;
            }
        }

        return result;
    }
};
