class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos=0;
        int neg=0;
        for(int number:nums){
            if(number > 0)
              pos++;
            else if(number < 0)
                neg ++;
        }
        return max(pos,neg);
    }
};