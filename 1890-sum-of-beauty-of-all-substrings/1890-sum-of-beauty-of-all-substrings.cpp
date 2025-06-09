class Solution {
private:
    int getmaxcount(vector<int> freq) {
        int maxcount = 0;
        for(int i = 0; i < 26; i++) {
            maxcount = max(maxcount, freq[i]);
        }
        return maxcount;
    }

    int getmincount(vector<int> freq) {
        int mincount = INT_MAX;
        for(int i = 0; i < 26; i++) {
            if(freq[i] != 0) {
                mincount = min(mincount, freq[i]);
            }
        }
        return mincount;
    }

public:
    int beautySum(string s) {
        int sum = 0;
        for(int i = 0; i < s.length(); i++) {
            vector<int> freq(26, 0);
            for(int j = i; j < s.length(); j++) {
                freq[s[j] - 'a']++;
                int maxfreq = getmaxcount(freq);
                int minfreq = getmincount(freq);
                sum += (maxfreq - minfreq);
            }
        }
        return sum;
    }
};
