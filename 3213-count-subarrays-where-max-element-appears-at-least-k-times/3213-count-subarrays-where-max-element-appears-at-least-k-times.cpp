class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max = *max_element(nums.begin(), nums.end());
        int count = 0;
        long long ans=0;
        int l=0;
        int n = nums.size();
        for(int r=0; r<n; r++){
            if(nums[r] == max)
               count++;
            
            while(count >= k){
                ans += n - r;
                if(nums[l] == max){
                    count --;
                }
                l++;
            }
        }
        return ans;
    }
};