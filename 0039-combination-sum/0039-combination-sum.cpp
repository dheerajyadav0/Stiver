class Solution {
private:
    void helper(int i, int sum, vector<int>& s, vector<vector<int>>& res, vector<int>& candidates, int target) {
        if (i == candidates.size()) {
            if (sum == target) {
                res.push_back(s);
            }
            return;
        }

        // pick 
        if (sum + candidates[i] <= target) {
            s.push_back(candidates[i]);
            helper(i, sum + candidates[i], s, res, candidates, target); 
            s.pop_back(); 
        }
        //not pick
        helper(i + 1, sum, s, res, candidates, target);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> s;
        helper(0, 0, s, res, candidates, target);
        return res;
    }
};
