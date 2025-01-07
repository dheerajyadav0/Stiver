class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freqMap;

        // Count the frequency of each number
        for (int num : nums) {
            freqMap[num]++;
        }

        // Priority queue to sort by frequency, and by value descending if frequencies are equal
        auto cmp = [](pair<int, int> a, pair<int, int> b) {
            if (a.first == b.first) {
                return a.second < b.second; // Sort by value descending if frequency is the same
            }
            return a.first > b.first; // Sort by frequency ascending
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        // Push frequency and value into the priority queue
        for (auto& it : freqMap) {
            pq.push({it.second, it.first});
        }

        // Reconstruct the sorted array
        vector<int> result;
        while (!pq.empty()) {
            int count = pq.top().first;
            int value = pq.top().second;
            pq.pop();

            // Append the value `count` times
            while (count--) {
                result.push_back(value);
            }
        }

        return result;
    }
};
