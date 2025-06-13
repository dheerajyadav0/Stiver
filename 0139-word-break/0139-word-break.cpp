class Solution {
public:
    // bool wordBreak(string s, vector<string>& wordDict) {
    //     unordered_set<string> dict(wordDict.begin(), wordDict.end());
    //     return solve(s, dict);
    // }

    // bool solve(string s, unordered_set<string>& dict) {
    //     if (s.empty()) return true;

    //     for (int i = 1; i <= s.length(); i++) {
    //         string prefix = s.substr(0, i);
    //         if (dict.count(prefix)) {
    //             string suffix = s.substr(i);
    //             if (solve(suffix, dict)) return true;
    //         }
    //     }

    //     return false;

// DP
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> memo(s.length(), -1); // -1 = unvisited, 0 = false, 1 = true
        return solve(0, s, dict, memo);
    }

    bool solve(int start, string& s, unordered_set<string>& dict, vector<int>& memo) {
        if (start == s.length()) return true;
        if (memo[start] != -1) return memo[start];

        for (int end = start + 1; end <= s.length(); ++end) {
            if (dict.count(s.substr(start, end - start))) {
                if (solve(end, s, dict, memo)) {
                    return memo[start] = 1;
                }
            }
        }

        return memo[start] = 0;

    }
};
