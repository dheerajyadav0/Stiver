class Solution {
private:
    vector<int> buildLPS(string s) {
        vector<int> lps(s.size(), 0);
        int pre = 0, suf = 1;
        while (suf < s.size()) {
            if (s[pre] == s[suf]) {
                pre++;
                lps[suf] = pre;
                suf++;
            } else {
                if (pre == 0) {
                    lps[suf] = 0;
                    suf++;
                } else {
                    pre = lps[pre - 1];
                }
            }
        }
        return lps;
    }

public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;

        vector<int> lps = buildLPS(needle);
        int i = 0, j = 0;

        while (i < haystack.size()) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }

            if (j == needle.size()) {
                return i - j;
            } else if (i < haystack.size() && haystack[i] != needle[j]) {
                if (j == 0) {
                    i++;
                } else {
                    j = lps[j - 1];
                }
            }
        }

        return -1;
    }
};
