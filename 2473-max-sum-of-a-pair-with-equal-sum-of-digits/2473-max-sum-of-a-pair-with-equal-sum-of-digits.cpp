class Solution {
    private:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> freq;
        int res = -1;

        for (int it : nums) {
            int key = digitSum(it);
            if (freq.find(key) != freq.end()) {
                res = max(res, freq[key] + it );
                freq[key] = max(freq[key],it);
            } else {
                freq[key] = it ;
            }
        }

        return res;
    }
};