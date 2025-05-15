class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for (int d : digits) freq[d]++;
        vector<int> ans;
        for (int a = 1; a < 10; ++a) {
            if (freq[a] == 0) continue;
            freq[a]--;
            for (int b = 0; b < 10; ++b) {
                if (freq[b] == 0) continue;
                freq[b]--;
                for (int c = 0; c < 10; c += 2) {
                    if (freq[c] > 0) {
                        int num = a * 100 + b * 10 + c;
                        ans.push_back(num);
                    }
                }
                freq[b]++;
            }
            freq[a]++;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
