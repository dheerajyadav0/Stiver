class Solution {
    int MOD = 1e9+7;
    inline int modAdd(int a,int b){
        return ((a % MOD)+(b % MOD))% MOD;
    }
public:
    int lengthAfterTransformations(string s, int t) {
        array<int,26> sfreq{};
        for(char c: s)
            sfreq[c-'a']++;
        
        for(int i=1;i<=t;++i){
            array<int,26> nfreq{};
            for(int j=0;j<26;++j){
                if(j<25)
                    nfreq[j+1] = sfreq[j];
                else{
                    nfreq[0] = sfreq[25];
                    nfreq[1] = modAdd(nfreq[1],sfreq[25]);
                }
            }
            sfreq = nfreq;
        }
        int size = 0;
        for(int i=0;i<26;++i)
            size = modAdd(size,sfreq[i]);
        
        return size;
    }
};