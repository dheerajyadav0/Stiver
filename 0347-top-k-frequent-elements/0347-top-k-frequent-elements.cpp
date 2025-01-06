class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
    for (int num : nums) {
        freqMap[num]++;
    }

    // Step 2: Use a min-heap to track the top k frequent elements
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    for (auto it : freqMap) {
        minHeap.push({it.second, it.first}); // Store {frequency, element}
        if (minHeap.size() > k) {
            minHeap.pop(); // Remove the least frequent element
        }
    }

    // Step 3: Extract the elements from the heap
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }

    return result;
    }
};