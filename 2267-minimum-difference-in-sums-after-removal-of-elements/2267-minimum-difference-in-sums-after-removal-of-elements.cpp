class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int N = nums.size();
        int n = N / 3;

        vector<long long> lsum(N, 0);
        vector<long long> rsum(N, 0);

        priority_queue<int> maxh;
        long long leftsum = 0;
        for (int i = 0; i < 2 * n; i++) {
            maxh.push(nums[i]);
            leftsum += nums[i];

            if (maxh.size() > n) {
                leftsum -= maxh.top();
                maxh.pop();
            }

            if (maxh.size() == n)
                lsum[i] = leftsum;
        }

        priority_queue<int, vector<int>, greater<int>> minh;
        long long rightsum = 0;
        for (int i = N - 1; i >= n; i--) {
            minh.push(nums[i]);
            rightsum += nums[i];

            if (minh.size() > n) {
                rightsum -= minh.top();
                minh.pop();
            }

            if (minh.size() == n)
                rsum[i] = rightsum;
        }

        long long res = LLONG_MAX;
        for (int i = n - 1; i < 2 * n; i++) {
            res = min(res, lsum[i] - rsum[i + 1]);
        }

        return res;
    }
};
