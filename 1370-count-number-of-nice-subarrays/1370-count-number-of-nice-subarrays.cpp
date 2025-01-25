class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(); 
        unordered_map<int, int> mpp; 
        int sum = 0; 
        int ans = 0;
        mpp[0] = 1; 
        for (int i = 0; i < n; ++i) { 
            if (nums[i] % 2 == 1) { 
                sum += 1;
            }
            int diff = sum - k; 
            ans += mpp[diff]; 
            mpp[sum]++; 
        }
        return ans; 
    }
};