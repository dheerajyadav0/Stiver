class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string combined = s + "#" + rev;

        vector<int> lps(combined.size(), 0);

        for (int i = 1; i < combined.size(); ++i) {
            int len = lps[i - 1];
            while (len > 0 && combined[i] != combined[len]) {
                len = lps[len - 1];
            }
            if (combined[i] == combined[len]) {
                len++;
            }
            lps[i] = len;
        }

        string suffix = s.substr(lps.back());
        reverse(suffix.begin(), suffix.end());
        return suffix + s;
    }
};
