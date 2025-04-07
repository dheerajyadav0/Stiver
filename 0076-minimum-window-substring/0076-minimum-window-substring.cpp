class Solution {
public:
    string minWindow(string s, string t) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        int len1 = s.length();
        int len2 = t.length();

        if (len1 < len2) return "";

        unordered_map<char, int> required, window;
        for (char ch : t) {
            required[ch]++;
        }

        int start = 0, matched = 0;
        int minLen = INT_MAX, minStart = 0;

        for (int end = 0; end < len1; end++) {
            char endChar = s[end];
            window[endChar]++;

            if (required.count(endChar) && window[endChar] <= required[endChar]) {
                matched++;
            }

            // try to shrink the window
            while (matched == len2) {
                if ((end - start + 1) < minLen) {
                    minLen = end - start + 1;
                    minStart = start;
                }

                char startChar = s[start];
                window[startChar]--;

                if (required.count(startChar) && window[startChar] < required[startChar]) {
                    matched--;
                }

                start++;
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(minStart, minLen);
    }
};
