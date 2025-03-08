class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int w = 0 ; 
        for(int i = 0 ;i<k;i++){
            if(blocks[i]=='W') w++;
        }
        int result = w;
        int n = blocks.size() ;
        for(int i =1 ; i<= n-k; i++){
            if(blocks[i-1] == 'W')w--;
            if(blocks[i+k-1] == 'W')w++;
             result = min(result, w);

        }
        
    return result ;
    }
};