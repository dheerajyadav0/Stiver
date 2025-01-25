class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, maxf = 0, maxLen = 0;
        vector<int> hash(26,0);
        while(r < s.size()){
            hash[s[r]-'A'] ++;
            maxf = max(maxf, hash[s[r]-'A']);
            int length = r-l+1;
            int changes = length - maxf;
            if(changes > k){
                hash[s[l]-'A'] --;
                l++;
            }
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};