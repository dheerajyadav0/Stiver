class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (int num : nums) {
            pq.push(num);
        }
        long long score = 0;
        while (k!=0) {
            int top = pq.top(); pq.pop();
            score += top;
            int c = ceil((double)top/ 3);
            pq.push(c);
            k--;
        }

        return score;
    }
};
