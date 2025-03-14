class Solution {
public:
bool can(int mid,vector<int>& candies,long long k){
    long long  count = 0;
    for(int i=0;i<candies.size();i++){
        long long diff = candies[i]/mid;
        count+= diff;
    }
    return count>=k;
}
    int maximumCandies(vector<int>& candies, long long k) {
        int left = 1,right = *max_element(candies.begin(),candies.end());
        int ans =0;
        while(left<=right){
            int mid = left +(right-left)/2;
            if(can(mid,candies,k)){
                ans = mid;
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return ans;
    }
};