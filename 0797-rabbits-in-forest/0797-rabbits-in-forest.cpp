class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int>mpp;
        int total = 0;

        for (auto it : answers) {
            if (mpp[it] == 0) {
               
                total += it + 1;  
                mpp[it] = it;  
            } else {
                
                mpp[it]--;
            }
        }

        return total;
    }
};
