class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        
        unordered_set<int>st;
        for(auto it : nums){
            st.insert(it);
        }
        int count = 0 ;
        for(int i = 0 ; i<nums.size();i++){
            
            unordered_set<int>stt;
            stt.insert(nums[i]);
            if(st.size()== stt.size()){
                count++;

            }
            for(int j = i+1; j<nums.size();j++){
                stt.insert(nums[j]);
                if(st.size()== stt.size()){
                    count++;
                }
            }
        
        }
        return count ;
    }
};