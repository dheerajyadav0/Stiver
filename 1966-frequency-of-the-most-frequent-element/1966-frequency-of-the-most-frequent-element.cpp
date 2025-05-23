class Solution {
public:
   int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end()); 
    long long total = 0;
    int l = 0, maxFreq = 0;

    for (int r = 0; r < nums.size(); ++r) {
        total += nums[r];
        int len = r - l + 1;

        while ((long long)nums[r] * len >= total + k + 1) {
            total -= nums[l];
            l++;
            len = r - l + 1; 
        }

        maxFreq = max(maxFreq, len);
    }

    return maxFreq;
}

};