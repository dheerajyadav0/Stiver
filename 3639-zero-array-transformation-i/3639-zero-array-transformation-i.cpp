class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>diff(n+1);
        for(auto v : queries){
            diff[v[0]]+=1;
            diff[v[1]+1]-=1;
        }
         vector<int> arr(n, 0);
         arr[0] = diff[0];
        for (int i = 1; i < n; ++i) {
            arr[i] = arr[i - 1] + diff[i];
        }

        for (int i = 0; i < n; ++i) {
            // if (arr[i] == 0 && nums[i] != 0) return false;
            // if (nums[i] > arr[i]) return false;
            if (arr[i] < nums[i]) return false;
        }

        return true;
    }
};