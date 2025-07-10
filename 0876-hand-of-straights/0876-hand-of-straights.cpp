class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if (n % groupSize != 0) return false;

       unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            mpp[hand[i]]++;
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& it : mpp) {
            pq.push(it.first);
        }

        while (!pq.empty()) {
            int first = pq.top();

            for (int i = 0; i < groupSize; i++) {
                int curr = first + i;

                if (mpp.find(curr) == mpp.end()) return false;

                mpp[curr]--;

                if (mpp[curr] == 0) {
                    mpp.erase(curr);

                   
                        pq.pop();
                    
                }
            }
        }

        return true;
    }
};
