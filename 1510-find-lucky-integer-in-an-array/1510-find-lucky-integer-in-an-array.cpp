class Solution {
    int luck = -1 ;
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mpp;
        for(auto freq : arr) {
            mpp[freq]++;
        }
        for(auto it: mpp){
            if(it.first == it.second) luck = max(luck,it.first);
            
        }
        return luck;
    }
};