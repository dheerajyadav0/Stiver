class Solution {
private:
    void helper(vector<string>& res, int n, int oc, int cc, string s) {
        if (oc == n && cc == n) {
            res.push_back(s);
            return;
        }
        if (oc < n) {
            helper(res, n, oc + 1, cc, s + "(");
        }
        if (cc < oc) {
            helper(res, n, oc, cc + 1, s + ")");
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(res, n, 0, 0, "");
        return res;
    }
};
