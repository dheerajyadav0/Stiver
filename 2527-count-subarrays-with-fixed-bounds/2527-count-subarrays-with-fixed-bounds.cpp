class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long count = 0;
        int left = 0;       
        int minPos = -1;    
        int maxPos = -1;    
        int badPos = -1;    

        for (int i = 0; i < n; ++i) {
            if (nums[i] < minK || nums[i] > maxK) {
                badPos = i;
            }
            if (nums[i] == minK) {
                minPos = i;
            }
            if (nums[i] == maxK) {
                maxPos = i;
            }

            int validStart = min(minPos, maxPos);
            if (validStart > badPos) {
                count += validStart - badPos;
            }
        }
        return count;
    }
};
