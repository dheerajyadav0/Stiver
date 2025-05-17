class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        int zero1 = 0, zero2 = 0;

        for (int num : nums1) {
            if (num == 0) zero1++;
            else sum1 += num;
        }

        for (int num : nums2) {
            if (num == 0) zero2++;
            else sum2 += num;
        }

        long long minSum1 = sum1 +  zero1;
        long long minSum2 = sum2 +  zero2;

        if (sum1 == sum2 && zero1 == 0 && zero2 == 0)
            return sum1;

        if ((minSum1 > sum2 && zero2 == 0) || (minSum2 > sum1 && zero1 == 0))
            return -1;

        return max(minSum1, minSum2);
    }
};
