class Solution {
public:
    int atMostK(vector<int>& nums, int k) {
        int l = 0, r = 0, res = 0;
        unordered_map<int, int> mpp;

        for (r = 0; r < nums.size(); ++r) {
            if (mpp[nums[r]] == 0) {
                k--;
            }
            mpp[nums[r]]++;

            while (k < 0) {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0) {
                    k++;
                }
                l++;
            }

            res += r - l + 1;
        }

        return res;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};
