class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int k=trust.size();
        if(!k) return n<=1?1:-1;
        unordered_map<int,int> m, t;
        for(int i=0;i<k;i++){
            m[trust[i][1]]++;
            t[trust[i][0]]++;
        }
        for(auto i:m){
            if(i.second==n-1&&t[i.first]==0) return i.first;
        }
        return -1;
    }
};