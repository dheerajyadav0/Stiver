class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> minHeap(nums.begin(), nums.end());

        int operations = 0;

        while (minHeap.top() < k) {
            if (minHeap.size() < 2) return -1;  
            long long a = minHeap.top(); minHeap.pop();
            long long b = minHeap.top(); minHeap.pop();

            long long newVal = min(a, b) * 2 + max(a, b);
            
            minHeap.push(newVal);
            operations++;
        }
        
        return operations;
    }
};
