class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans = 0;
        int l = 0;
        long long pairs = 0;
        int n = nums.size();
        unordered_map<int,int> freq;
        for(int r = 0; r<n; ++r){
            pairs += freq[nums[r]];
            freq[nums[r]]++;
           
            while(pairs>=k){
                ans += (n-r);
                pairs -= (freq[nums[l]] - 1);
                freq[nums[l]]--;
                l++;
            }
        }
        return ans;
    }
};