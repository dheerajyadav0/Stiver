class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> mpp;  
        unordered_map<int, int> colorCount;  
        vector<int> ans; 
        
        int distinctColorCount = 0;          
        for (auto& it : queries) {
            int x = it[0], y = it[1];


            if (mpp.find(x) != mpp.end()) {
                int prevColor = mpp[x];
             
                if (--colorCount[prevColor] == 0) {
                    colorCount.erase(prevColor);  
                    distinctColorCount--;  
                }
            }

            mpp[x] = y;
            
            
            if (colorCount[y]++ == 0) {
                distinctColorCount++;
            }

           
            ans.push_back(distinctColorCount);
        }

        return ans;
    }
};