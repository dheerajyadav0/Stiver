class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int oreo = 0 ;
        for(auto it : nums){
            oreo |=it;
        }
            return oreo *(1<<(n-1));
        
    }
};