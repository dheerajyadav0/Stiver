class Solution {
public:
    int maxDepth(string s) {
        int curr=0 ;
        int res =0 ; 
        for(auto i : s){
            if(i=='(') res = max(res,++curr);
            if(i==')') curr--;
        }
        return res;
    }
};