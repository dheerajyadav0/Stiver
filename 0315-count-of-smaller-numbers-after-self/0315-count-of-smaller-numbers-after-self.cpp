class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int> a=nums;
        vector<int> ans(n,0);
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++){
            int in=lower_bound(a.begin(),a.end(),nums[i])-a.begin();
            ans[i]=in;
            if(in<a.size()) a.erase(a.begin()+in);
        }
        return ans;
    }
};