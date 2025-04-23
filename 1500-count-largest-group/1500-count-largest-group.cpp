class Solution {
private:
    int summ(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> mpp;
        int maxSize = 0;

        for (int i = 1; i <= n; ++i) {
            int sum = summ(i);
            mpp[sum]++;
            maxSize = max(maxSize, mpp[sum]);
        }

        int count = 0;
       for (const auto& it : mpp) {
            if (it.second == maxSize) {
        count++;
    }
}

        return count;
    }
};
