class Solution {
private:
    void helper(int ind, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans) {
        if (ind == nums.size()) {
            ans.push_back(ds);
            return;
        }

        ds.push_back(nums[ind]);
        helper(ind + 1, nums, ds, ans);
        ds.pop_back();

      
        while (ind + 1 < nums.size() && nums[ind] == nums[ind + 1]) {
            ind++;
        }

     
        helper(ind + 1, nums, ds, ans);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        helper(0, nums, ds, ans);
        return ans;
    }
};
